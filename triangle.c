#define _CRT_SECURE_NO_WARNINGS // Visual Studio only
#include <stdio.h>
#include <math.h>

// 角度を計算する。
// a, b, c は辺の長さ。angle_A, angle_B, angle_C は角度「°」
void calc_angle(double a, double b, double c,
    double *angle_A, double *angle_B, double *angle_C) {
    double pi = acos(-1); // 円周率を求める。

// 余弦定理により角度(ラジアン)を計算する。
    *angle_A = acos((b*b + c*c - a*a) / (2*b*c));
    *angle_B = acos((c*c + a*a - b*b) / (2*c*a));
    *angle_C = acos((a*a + b*b - c*c) / (2*a*b));
// ラジアンから度数「°」へ変換する。
    *angle_A = *angle_A * 180 / pi;
    *angle_B = *angle_B * 180 / pi;
    *angle_C = *angle_C * 180 / pi;
}

// ヘロンの公式により面積を計算する。
// a, b, c は辺の長さ。
double calc_area(double a, double b, double c) {
    double s = (a + b + c) / 2;

    return sqrt(s * (s-a) * (s-b) * (s-c));
}

// 三角形か判定する。
// 三角形のとき 1 を返す。三角形でないとき 0 を返す。
int is_triangle(double a, double b, double c) {
    if (a >= b + c) return 0;
    if (b >= a + c) return 0;
    if (c >= a + b) return 0;
    return 1;
}

int main(void) {
    double a, b, c; // 辺の長さ

    printf("三角形の３辺(a b c)を入力してください。\n");
    printf("各数値は空白か改行で区切ってください。\n");
    scanf("%lf%lf%lf", &a, &b, &c);

    if (is_triangle(a, b, c)) {
        printf("三角形です。\n");
    } else {
        printf("三角形ではありません。\n");
        return 0;
    }

    double angle_A, angle_B, angle_C; // 角度
    calc_angle(a, b, c, &angle_A, &angle_B, &angle_C);
    printf("三角形の辺  (a b c)は %15.8f %15.8f %15.8f\n", a, b, c);
    printf("三角形の角度(A B C)は %15.8f %15.8f %15.8f\n", angle_A, angle_B, angle_C);
    printf("三角形の面積は %15.8f\n", calc_area(a, b, c));
    return 0;
}
