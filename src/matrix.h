class Matrix{
public:
    // 行列の行数
    int nrow;
    // 行列の列数
    int ncol;
    // 行列の要素の配列
    double* array;

    //　コンストラクタ
    Matrix(int nrow, int ncol);
};