class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m_matrix = matrix;
        int m = matrix.size(), n = matrix[0].size();

        m_preSum.assign(m, vector<int>(n, 0));


        int preX = 0;
        int preK = 0;
        for(int i = 0; i < m; i++) {
            preX = 0;
            for(int j = 0; j < n; j++) {
                preK = 0;
                for(int k = 0; k <= i; k++){
                    preK += matrix[i-k][j];
                }
                m_preSum[i][j] = preK + preX;
                preX = m_preSum[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 == col1 && row1 == 0) return m_preSum[row2][col2];
        if(row1 == 0) return m_preSum[row2][col2] - m_preSum[row2][col1-1];
        if(col1 == 0) return m_preSum[row2][col2] - m_preSum[row1-1][col2];
        return m_preSum[row2][col2] - m_preSum[row1-1][col2] - (m_preSum[row2][col1-1] - m_preSum[row1-1][col1-1]);
    }

private: 
    vector<vector<int>> m_matrix;
    vector<vector<int>> m_preSum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */