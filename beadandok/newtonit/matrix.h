using namespace std;

template<typename T>
class Matrix
{
    public:
        //konstruktorok
        Matrix<T>(int lines, int cols)
            : L(lines), C(cols), matrix(lines * cols)
        {}

        double& operator()(int lines, int cols)
        {
            return matrix[lines*C + cols];
        }

        const double& operator()(int lines, int cols) const{
            return matrix[lines*C + cols];
        }

        
        
          

        //osszeadas 
        
        Matrix<T> operator+(const Matrix& B){
            Matrix<T> res(L, C);
            for (int i=0; i < matrix.size(); i++)
             res.matrix[i]=matrix[i]+B.matrix[i];
            return res;
        }   
        

        //kivonas 
        Matrix<T> operator-(const Matrix& B) {
            Matrix<T> res(L, C);
            for (int i=0; i < matrix.size(); i++)
             res.matrix[i]=matrix[i]-B.matrix[i];
            return res;
        }

        //skalar szorzas
        Matrix<T> operator*(double skalar) {
            Matrix<T> res(L, C);
            for (int i=0; i < matrix.size(); i++)
             res.matrix[i]=matrix[i]*skalar;
            return res;
        }

        //skalar osztas 
        Matrix<T> operator/(double skalar) {
            Matrix<T> res(L, C);
            for (int i=0; i < matrix.size(); i++)
             res.matrix[i]=matrix[i]/skalar;
            return res;
        }

        //matrix szorzas 
        Matrix<T> operator*(const Matrix& B) {
            Matrix<T> res(L, C);
            for (int i=0; i < matrix.size(); i++)
             res.matrix[i]=matrix[i]*B.matrix[i];
            return res;
        }

        //kiiras

        friend std::ostream& operator<<(std::ostream& os, const Matrix& A)
        {
            for (int i=0; i<A.L; i++)
            {
                for (int j=0; j<A.C; j++)
                {
                    os<<A(i,j)<<" ";
                }
                os<<std::endl;
            }
            return os;
        }


        /*
        
        Matrix<T> operator+(Matrix&& B)
        {
            for (int i=0; i<matrix.size(); i++)
            {
                B.matrix[i]=matrix[i]+B.matrix[i];
            }
            return std::move(B);
        }
        Matrix<T> operator-(Matrix&& B)
        {
            for (int i=0; i<matrix.size(); i++)
            {
                B.matrix[i]=matrix[i]-B.matrix[i];
            }
            return std::move(B);
        }
        Matrix<T> operator*(double scalar)
        {
            for (int i=0; i<matrix.size(); i++)
            {
                matrix[i]=matrix[i]*scalar;
            }
            return std::move(*this);
        }
        Matrix<T> operator/(double scalar)
        {
            for (int i=0; i<matrix.size(); i++)
            {
                matrix[i]=matrix[i]*scalar;
            }
            return std::move(*this);
        }
        */





    private:
        int L;
        int C;
        std::vector<double> matrix;
};

