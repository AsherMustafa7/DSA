class Solution {
public:

    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        int sr = -1;
        int sc = -1;

        // Give every litter a number
        vector<vector<int>> litterId(m, vector<int>(n, -1));

        int litterCount = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if(classroom[i][j] == 'L') {
                    litterId[i][j] = litterCount;
                    litterCount++;
                }
            }
        }

        int fullMask = (1 << litterCount) - 1;

        // best[r][c][mask] = maximum energy
        // with which we have reached this state
        vector<vector<vector<int>>> best(
            m,
            vector<vector<int>>(
                n,
                vector<int>(1 << litterCount, -1)
            )
        );

        struct State {
            int r;
            int c;
            int energy;
            int mask;
        };

        queue<State> q;

        q.push({sr, sc, energy, 0});

        best[sr][sc][0] = energy;

        int moves = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()) {

            int size = q.size();

            for(int p = 0; p < size; p++) {

                State cur = q.front();
                q.pop();

                int r = cur.r;
                int c = cur.c;
                int e = cur.energy;
                int mask = cur.mask;

                // All litter collected
                if(mask == fullMask) {
                    return moves;
                }

                // Try four directions
                for(int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if(nr < 0 || nr >= m ||
                       nc < 0 || nc >= n) {
                        continue;
                    }

                    // Cannot move through obstacles
                    if(classroom[nr][nc] == 'X') {
                        continue;
                    }

                    // Need energy to make the move
                    if(e == 0) {
                        continue;
                    }

                    int ne = e - 1;

                    int newMask = mask;

                    // Collect litter
                    if(classroom[nr][nc] == 'L') {

                        int id = litterId[nr][nc];

                        newMask |= (1 << id);
                    }

                    // Reset energy
                    if(classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    // If this state was already reached
                    // with more energy, skip it
                    if(best[nr][nc][newMask] >= ne) {
                        continue;
                    }

                    best[nr][nc][newMask] = ne;

                    q.push({
                        nr,
                        nc,
                        ne,
                        newMask
                    });
                }
            }

            moves++;
        }

        return -1;
    }
};