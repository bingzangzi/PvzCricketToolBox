/********************************************************************************
** Form generated from reading UI file 'versioninfo.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERSIONINFO_H
#define UI_VERSIONINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_versioninfo
{
public:
    QTextBrowser *textBrowser;
    QPushButton *pushButton;

    void setupUi(QWidget *versioninfo)
    {
        if (versioninfo->objectName().isEmpty())
            versioninfo->setObjectName("versioninfo");
        versioninfo->resize(508, 337);
        textBrowser = new QTextBrowser(versioninfo);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(30, 30, 451, 271));
        pushButton = new QPushButton(versioninfo);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(380, 300, 100, 30));

        retranslateUi(versioninfo);

        QMetaObject::connectSlotsByName(versioninfo);
    } // setupUi

    void retranslateUi(QWidget *versioninfo)
    {
        versioninfo->setWindowTitle(QCoreApplication::translate("versioninfo", "Form", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("versioninfo", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\347\211\210\346\234\254\357\274\232ver 1.0.0\346\255\243\345\274\217\347\211\210</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\210\266\344\275\234\357\274\232bilibili@\351\245\274\350\227\217\345\255\220_</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; mar"
                        "gin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\347\211\210\346\234\254\346\233\264\346\226\260\344\277\241\346\201\257\357\274\232</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1.\346\234\254\347\211\210\344\270\272\346\234\254\350\275\257\344\273\266\347\254\254\344\270\200\344\270\252\346\255\243\345\274\217\347\211\210\357\274\214\346\254\242\350\277\216\345\244\247\345\256\266\344\275\277\347\224\250\357\274\201</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">2.\346\234\211\344\273\273\344\275\225\351\227\256\351\242\230\345\205\210\346\237\245\347\234\213\345\270\256\345\212\251\357\274\214\344\271\237\345\217\257\344\273\245\345\222\250\350\257\242up\344\270\273\343\200\202</p>\n"
"<p style=\" margin-t"
                        "op:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">3.\345\234\250\344\275\277\347\224\250\344\270\255\345\217\257\350\203\275\345\207\272\347\216\260\350\275\257\344\273\266\345\264\251\346\272\203\347\232\204\351\227\256\351\242\230\357\274\214\345\217\257\344\273\245\346\240\271\346\215\256\345\270\256\345\212\251\344\270\255\347\232\204\346\217\220\347\244\272\345\256\232\344\275\215\351\227\256\351\242\230\357\274\214\345\271\266\345\217\215\351\246\210\347\273\231up\344\270\273\343\200\202</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">4.\346\254\242\350\277\216\345\220\204\344\275\215\345\244\247\344\275\254\345\257\271\346\234\254\350\275\257\344\273\266\347\232\204\344\273\243\347\240\201\346\210\226\345\212\237\350\203\275\347\273\231\345\207\272\345\273\272\350\256\256\346\210\226\346\224\271\350\277\233\346\226\271\346\241\210\357\274\201</p>\n"
"<p style=\" margin-top:"
                        "0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">5.\346\234\211\344\273\273\344\275\225\351\234\200\350\246\201\347\232\204\345\212\237\350\203\275\345\217\257\344\273\245\345\220\221up\344\270\273\346\217\220\345\207\272\357\274\214\345\217\257\350\203\275\344\274\232\345\234\250\345\220\216\347\273\255\347\211\210\346\234\254\344\270\255\345\242\236\345\212\240\343\200\202</p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("versioninfo", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class versioninfo: public Ui_versioninfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERSIONINFO_H
