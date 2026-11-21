class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m_matrix = matrix;
        m_preSumX.assign(matrix.size(), vector<int>(matrix[0].size(), 0));
        // m_preSumY.assign(matrix.size(), vector<int>(matrix[0].size(), 0));
        // m_preSumTotal.assign(matrix.size(), vector<int>(matrix[0].size(), 0));


        int preX = 0;
        int preK = 0;
        for(int i = 0; i < matrix.size(); i++) {
            preX = 0;
            for(int j = 0; j < matrix[0].size(); j++) {
                preK = 0;
                for(int k = 0; k <= i; k++){
                    preK += matrix[i-k][j];
                }
                m_preSumX[i][j] = preK + preX;
                preX = m_preSumX[i][j];
            }
        }

        // int preY = 0;
        // for(int j = 0; j < matrix.size(); j++) {
        //     preY = 0;
        //     for(int i = 0; i < matrix[0].size(); i++) {
        //         m_preSumY[i][j] = matrix[i][j] + preY;
        //         preY = m_preSumY[i][j];
        //     }
        // }

        // int preTotal = 0;
        // for(int i = 0; i < matrix.size(); i++) {
        //     preTotal = 0;
        //     for(int j = 0; j < matrix[0].size(); j++) {
        //         if(j == 0) {
        //             m_preSumTotal[i][j] = m_preSumY[i][j];
        //             preTotal = m_preSumTotal[i][j];
        //             continue;
        //         }
        //         if(i == 0) {
        //             m_preSumTotal[i][j] = m_preSumX[i][j];
        //             preTotal = m_preSumTotal[i][j];
        //             continue;
        //         }

        //         m_preSumTotal[i][j] = m_preSumX[i-1][j] + m_preSumY[i][j-1] + preTotal;
        //         preTotal = m_preSumTotal[i][j];
        //     }
        // }

        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                cout << m_preSumX[i][j] ;
                cout << " | " ; 
            }
            cout << endl;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 == col1 && row1 == 0) return m_preSumX[row2][col2];
        if(row1 == 0) return m_preSumX[row2][col2] - m_preSumX[row2][col1-1];
        if(col1 == 0) return m_preSumX[row2][col2] - m_preSumX[row1-1][col2];
        cout << m_preSumX[row2][col2] << endl;
        cout << m_preSumX[row1-1][col2] << endl;
        cout << m_preSumX[row2][col1-1] << endl;
        cout << m_preSumX[row1-1][col1-1] << endl;
        return m_preSumX[row2][col2] - m_preSumX[row1-1][col2] - (m_preSumX[row2][col1-1] - m_preSumX[row1-1][col1-1]);
    }

private: 
    vector<vector<int>> m_matrix;
    vector<vector<int>> m_preSumX;
    vector<vector<int>> m_preSumY;
    vector<vector<int>> m_preSumTotal;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */