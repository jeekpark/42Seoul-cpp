/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:54:27 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/07 15:57:27 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

struct Point {
    double x, y;
};

bool isInsideTriangle(const Point& A, const Point& B, const Point& C, const Point& D) {
    // 1. denominator는 바리센트릭 좌표 계산의 분모 부분입니다.
    double denominator = ((B.y - C.y) * (A.x - C.x) + (C.x - B.x) * (A.y - C.y));
    
    // 2. a와 b는 바리센트릭 좌표를 계산하기 위한 값들입니다.
    double a = ((B.y - C.y) * (D.x - C.x) + (C.x - B.x) * (D.y - C.y)) / denominator;
    double b = ((C.y - A.y) * (D.x - C.x) + (A.x - C.x) * (D.y - C.y)) / denominator;
    
    // 3. c의 값은 a와 b를 이용하여 간단하게 구할 수 있습니다. (a + b + c = 1이므로)
    double c = 1 - a - b;

    // 4. 모든 가중치가 0과 1 사이에 있다면 점 D는 삼각형 내부에 있습니다.
    return a >= 0 && a <= 1 && b >= 0 && b <= 1 && c >= 0 && c <= 1;
}

int main() {
    Point A = {0, 0};
    Point B = {10, 0};
    Point C = {0, 10};
    Point D = {1, 9.1};

    if(isInsideTriangle(A, B, C, D)) {
        std::cout << "Point D is inside triangle ABC." << std::endl;
    } else {
        std::cout << "Point D is not inside triangle ABC." << std::endl;
    }

    return 0;
}