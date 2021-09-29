#include "helper_functions.h"

#include <libutils/rasserts.h>


cv::Mat makeAllBlackPixelsBlue(cv::Mat image) {
    // TODO реализуйте функцию которая каждый черный пиксель картинки сделает синим

    // ниже приведен пример как узнать цвет отдельного пикселя - состоящий из тройки чисел BGR (Blue Green Red)
    // чем больше значение одного из трех чисел - тем насыщеннее его оттенок
    // всего их диапазон значений - от 0 до 255 включительно
    // т.е. один байт, поэтому мы используем ниже тип unsigned char - целое однобайтовое неотрицательное число
    cv::Vec3b color = image.at<cv::Vec3b>(13, 5); // взяли и узнали что за цвет в пикселе в 14-ом ряду (т.к. индексация с нуля) и 6-ой колонке
    unsigned char blue = color[0]; // если это число равно 255 - в пикселе много синего, если равно 0 - в пикселе нет синего
    unsigned char green = color[1];
    unsigned char red = color[2];
    for(int i=0; i<image.cols; i++) {
        for(int j=0; j<image.rows; j++) {
            cv::Vec3b color = image.at<cv::Vec3b>(j, i);
            if (color[0] == 0 && color[1] == 0 && color[2] == 0) {
                image.at<cv::Vec3b>(j,i) = cv::Vec3b(255, 0, 0);
            }
        }
    }
    // как получить белый цвет? как получить черный цвет? как получить желтый цвет?
    // поэкспериментируйте! например можете всю картинку заполнить каким-то одним цветом

    // пример как заменить цвет по тем же координатам
    red = 255;
    // запустите эту версию функции и посмотрите на получившуюся картинку - lesson03/resultsData/01_blue_unicorn.jpg
    // какой пиксель изменился? почему он не чисто красный?
    image.at<cv::Vec3b>(13, 5) = cv::Vec3b(blue, green, red);

    return image;
}

cv::Mat invertImageColors(cv::Mat image) {
    // TODO реализуйте функцию которая каждый цвет картинки инвертирует:
    // т.е. пусть ночь станет днем, а сумрак рассеется
    // иначе говоря замените каждое значение яркости x на (255-x) (т.к находится в диапазоне от 0 до 255)
    cv::Vec3b color = image.at<cv::Vec3b>(13,
                                          5); // взяли и узнали что за цвет в пикселе в 14-ом ряду (т.к. индексация с нуля) и 6-ой колонке
    unsigned char blue = color[0];
    unsigned char green = color[1];
    unsigned char red = color[2];
    for (int i = 0; i < image.cols; i++) {
        for (int j = 0; j < image.rows; j++) {
            cv::Vec3b color = image.at<cv::Vec3b>(j, i);
            image.at<cv::Vec3b>(j, i) = cv::Vec3b(255 - color[0], 255 - color[1], 255 - color[2]);
        }
    }
    image.at<cv::Vec3b>(13, 5) = cv::Vec3b(blue, green, red);
    return image;
}


cv::Mat addBackgroundInsteadOfBlackPixels(cv::Mat object, cv::Mat background) {
    // TODO реализуйте функцию которая все черные пиксели картинки-объекта заменяет на пиксели с картинки-фона
    // т.е. что-то вроде накладного фона получится

    // гарантируется что размеры картинок совпадают - проверьте это через rassert, вот например сверка ширины:
    rassert(object.cols == background.cols, 341241251251351);
    rassert(object.rows == background.rows, 341241251251351);

    for( int i = 0; i < object.cols; i++){
        for( int j = 0; j < object.rows; j++){
            cv::Vec3b color = background.at<cv::Vec3b>(j, i);
            cv::Vec3b color1 = object.at<cv::Vec3b>(j, i);
            if(color1[0] == 0 && color1[1] == 0 && color1[2] == 0){
                object.at<cv::Vec3b>(j, i) = background.at<cv::Vec3b>(j, i);
            }


        }
    }

    return object;
}

cv::Mat addBackgroundInsteadOfBlackPixelsLargeBackground(cv::Mat object, cv::Mat lB) {
    // теперь вам гарантируется что largeBackground гораздо больше - добавьте проверок этого инварианта (rassert-ов)
    rassert(object.cols <= lB.cols, 341241251251351);
    rassert(object.rows <= lB.rows, 341241251251351);
    // TODO реализуйте функцию так, чтобы нарисовался объект ровно по центру на данном фоне, при этом черные пиксели объекта не должны быть нарисованы
    for( int i = 0; i < object.cols; i++){
        for( int j = 0; j < object.rows; j++) {

            cv::Vec3b color = object.at<cv::Vec3b>(j, i);
            if (color[0] == 0 && color[1] == 0 && color[2] == 0) {

            }
            else{
                lB.at<cv::Vec3b>(j+lB.rows/2, i+lB.cols/2) = object.at<cv::Vec3b>(j, i);
            }



        }


    }

    return lB;
}
cv::Mat addBackgroundInsteadOfBlackPixelsLargeBackgroundN(cv::Mat object, cv::Mat lB,int n) {

    for (int a=0; a < n;a++){
       int b = rand() % (lB.rows -object.rows+1);
        int c = rand() % (lB.cols -object.cols+1);
         for( int i = 0; i < object.cols; i++){
            for( int j = 0; j < object.rows; j++) {
                cv::Vec3b color = object.at<cv::Vec3b>(j, i);
                if (color[0] == 0 && color[1] == 0 && color[2] == 0) {

                }
                else{
                    lB.at<cv::Vec3b>(j+b, i+c) = object.at<cv::Vec3b>(j, i);
                }

            }
        }
            }
        return lB;
}



/*cv::Mat  lust(cv::Mat object, cv::Mat lB){
    for( int i = 0; i < lB.cols; i++){
        for( int j = 0; j < lB.rows; j++) {
            int a = j/((double)lB.rows/(double)object.rows);
            int b = i/((double)lB.cols/(double)object.cols);
            lB.at<cv::Vec3b>(j, i) = object.at<cv::Vec3b>(a, b);
        }
    }

}*/

cv::Mat f(cv::Mat object,cv::Mat lB){


    for(int i = 0; i < lB.cols; i++){
        for(int j = 0; j < lB.rows; j++){

            double a = (double)lB.rows/(double)object.rows;
            double b = (double)lB.cols/(double)object.cols;

                lB.at<cv::Vec3b>(j, i) = object.at<cv::Vec3b>((double)j/a, (double)i/b);

        }
    }
    return lB;
}

cv::Mat f1(cv::Mat object) {
    for (int i = 0; i < object.cols; i++) {
        for (int j = 0; j < object.rows; j++) {
            cv::Vec3b color_object = object.at<cv::Vec3b>(j, i);


            if (color_object[0] == 0 && color_object[1] == 0 && color_object[2] == 0) {
                object.at<cv::Vec3b>(j, i) = cv::Vec3b(rand() % 255, rand() % 255, rand() % 255);
            }


        }
    }
    return object;
}