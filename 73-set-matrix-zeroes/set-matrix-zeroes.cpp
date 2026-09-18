class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (matrix[i][j] == 0) {
        //             for (int col = 0; col < n; col++) {
        //                 if (matrix[i][col] != 0) {
        //                     matrix[i][col] = -1;
        //                 }
        //             }
        //             for (int row = 0; row < m; row++) {
        //                 if (matrix[row][j] != 0) {
        //                     matrix[row][j] = -1;
        //                 }
        //             }
        //         }
        //     }
        // }
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (matrix[i][j] == -1) {
        //             matrix[i][j] = 0;
        //         }
        //     }
        // }



        // Track which rows and columns need to be zeroed
        vector<bool> rowZero(m, false);
        vector<bool> colZero(n, false);
        
        // 1. First pass: scan the matrix and record the zero locations
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    rowZero[i] = true;
                    colZero[j] = true;
                }
            }
        }
        
        // 2. Second pass: update the matrix using your tracker arrays
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rowZero[i] || colZero[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};