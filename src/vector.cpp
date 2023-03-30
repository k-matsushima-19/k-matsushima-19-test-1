#include <iostream>
#include <cmath>

class Vector2D {
public:
    // コンストラクター
    Vector2D(double x, double y) : m_x(x), m_y(y) {}

    // x成分を返すメソッド
    double getX() const { return m_x; }

    // y成分を返すメソッド
    double getY() const { return m_y; }

    // ベクトルの長さを返すメソッド
    double length() const { return std::sqrt(m_x * m_x + m_y * m_y); }

    // ベクトルの足し算を行うメソッド
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(m_x + other.m_x, m_y + other.m_y);
    }

    // ベクトルの引き算を行うメソッド
    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(m_x - other.m_x, m_y - other.m_y);
    }

    // ベクトルの内積を計算するメソッド
    double dot(const Vector2D& other) const {
        return m_x * other.m_x + m_y * other.m_y;
    }

    // ベクトルの外積を計算するメソッド
    double cross(const Vector2D& other) const {
        return m_x * other.m_y - m_y * other.m_x;
    }

private:
    double m_x;
    double m_y;
};

int main() {
    Vector2D v1(1.0, 2.0);
    Vector2D v2(3.0, 4.0);

    std::cout << "v1 = (" << v1.getX() << ", " << v1.getY() << ")" << std::endl;
    std::cout << "v2 = (" << v2.getX() << ", " << v2.getY() << ")" << std::endl;

    Vector2D v3 = v1 + v2;
    std::cout << "v1 + v2 = (" << v3.getX() << ", " << v3.getY() << ")" << std::endl;

    Vector2D v4 = v2 - v1;
    std::cout << "v2 - v1 = (" << v4.getX() << ", " << v4.getY() << ")" << std::endl;

    std::cout << "v1・v2 = " << v1.dot(v2) << std::endl;
    std::cout << "v1×v2 = " << v1.cross(v2) << std::endl;

    std::cout << "v1の長さ = " << v1.length() << std::endl;

    return 0;
}
