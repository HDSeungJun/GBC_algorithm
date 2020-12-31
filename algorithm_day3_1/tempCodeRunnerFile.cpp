    sort(e1, e1+4);
                sort(e2, e2+4);
                if(e1[3] == 0 && e2[3] == 0)
                    result = -1;
                else
                {
                    s_dist[i][j] += (e1[0]+e2[0]+1);
                }