#include <stdio.h>
#include <string.h>
#include <math.h>
#include<stdlib.h>

#define PI 3.1415926535

int fibonacci(int num) {
    if (num < 0) return 0; 
    if (num == 0 || num == 1) return 1; 
    int a = 0, b = 1, f = 0;
    while (f < num) {
        f = a + b;
        a = b;
        b = f;
    }
    return (f == num);
}


int amicable(int a, int b) {
    int sum_a = 0, sum_b = 0;
    for (int i = 1; i <= a / 2; i++) {
        if (a % i == 0) sum_a += i;
    }
    for (int i = 1; i <= b / 2; i++) {
        if (b % i == 0) sum_b += i;
    }
    return (sum_a == b && sum_b == a);
}

int main(){

    FILE *fin, *fout;
    fin = fopen("input.inp", "r");
    if (fin == NULL){
        printf("Error");
        exit(1);
    }

    fout = fopen("output.out", "w");
    if (fout == NULL){
        printf("Error");
        fclose(fin);
        exit(1);
    }

    int dc, dg, ld;
    int n;
    char w[10];
    char thoi_tiet[5][10] = {"Sun", "Wind", "Rain", "Fog", "Cloud"};
    int bc = 0, bg = 0;
    float nd;
    fscanf(fin, "%d %d %d %d %s", &n, &dc, &dg, &ld, w);

    if (n < 0 || n > 2000 || ld < 1 || ld > 600 || dc < 0 || dg < 0) {
        fprintf(fout, "-1 -1 %d", n);
        return 0;
    }
    
    int weather = 0;
    for (int i = 0; i < 5; i++) {
        if (strcmp(w, thoi_tiet[i]) == 0) {
            weather = 1;
            break;  
        } 
    }
    if(!weather) {
        fprintf(fout, "-1 -1 %d", n);
        fclose(fin);
        fclose(fout);
        return 1;
    }
    
    float nbc = pow(dc, 2) * sqrt(dc);
    float nbg = (pow(dg, 2) * PI )/ 3; 
    
    int ldbc = 1 + (dc >= 8);
    int ldbg = 1 + (dg >= 5); 
    
    float nep = n;
    if (strcmp("Wind", w) == 0){
        
        while(nep >= nbc && ld >= ldbc){
            bc++;
            nep -= nbc;
            ld -= ldbc;
        }

        while(nep >= nbg && ld >= ldbg){
            bg++;
            nep -= nbg;
            ld -= ldbg;
        }
            
    }

    else if(strcmp("Rain", w) == 0){
        while (nep >= nbc + nbg && ld >= ldbc + ldbg) {
            bc++;
            bg++;
            nep -= (nbc + nbg); 
            ld -= (ldbc + ldbg); 
        }
        
        if(dg > dc) {
            while(nep >= nbg && ld >= ldbg){
                bg++;
                nep -= nbg;
                ld -= ldbg;
            }
            
            while(nep >= nbc && ld >= ldbc){
                bc++;
                nep -= nbc;
                ld -= ldbc;
            }
        }

        else{
            while(nep >= nbc && ld >= ldbc){
                bc++;
                nep -= nbc;
                ld -= ldbc;
            }

            while(nep >= nbg && ld >= ldbg){
                bg++;
                nep -= nbg;
                ld -= ldbg;
            }
        }
    }


    else if (strcmp("Sun", w) == 0) {
        int G = dc % 6;
        int H = ld % 5;
        int table[5][6] = {
            {5, 7, 10, 12, 15, 20},
            {20, 5, 7, 10, 12, 15},
            {15, 20, 5, 7, 10, 12},
            {12, 15, 20, 5, 7, 10},
            {10, 12, 15, 20, 5, 7}
        };

        int X = table[H][G];
        n += n * X / 100;
        ld -= X;
        if (ld < 0) ld = 0;
        
        int new_weather = (dc + dg) % 3;
        if (new_weather == 0) {
            strcpy(w, "Rain");  
        } else if (new_weather == 1) {
            strcpy(w, "Wind"); 
        } else {
            strcpy(w, "Cloud");
        }

        nep = n;
        
        if (strcmp("Wind", w) == 0){
            if(dg > dc){
                while(nep >= nbg && ld >= ldbg){
                    bg++;
                    nep -= nbg;
                    ld -= ldbg;
                }
                
                while(nep >= nbc && ld >= ldbc){
                    bc++;
                    nep -= nbc;
                    ld -= ldbc;
                }
            }
            else{
                while(nep >= nbc && ld >= ldbc){
                    bc++;
                    nep -= nbc;
                    ld -= ldbc;
                }

                while(nep >= nbg && ld >= ldbg){
                    bg++;
                    nep -= nbg;
                    ld -= ldbg;
                }
            }  
        }

        else if(strcmp("Rain", w) == 0){
            while (nep >= nbc + nbg && ld >= ldbc + ldbg) {
                bc++;
                bg++;
                nep -= (nbc + nbg); 
                ld -= (ldbc + ldbg); 
            }
            
            if(dg > dc) {
                while(nep >= nbg && ld >= ldbg){
                    bg++;
                    nep -= nbg;
                    ld -= ldbg;
                }
                
                while(nep >= nbc && ld >= ldbc){
                    bc++;
                    nep -= nbc;
                    ld -= ldbc;
                }
            }

            else{
                while(nep >= nbc && ld >= ldbc){
                    bc++;
                    nep -= nbc;
                    ld -= ldbc;
                }

                while(nep >= nbg && ld >= ldbg){
                    bg++;
                    nep -= nbg;
                    ld -= ldbg;
                }
            }
        }

        else if (strcmp("Cloud", w) == 0) {
            if (amicable((int)nep, ld)) {
                fprintf(fout, "0 0 %.3f", nep);
                fclose(fin);
                fclose(fout);
                return 0;
            } 
            
            else {
                if(dg < dc){
                    while(nep >= nbg && ld >= ldbg){
                        bg++;
                        nep -= nbg;
                        ld -= ldbg;
                    }
                    
                    while(nep >= nbc && ld >= ldbc){
                        bc++;
                        nep -= nbc;
                        ld -= ldbc;
                    }
                }
                else{
                    while(nep >= nbc && ld >= ldbc){
                        bc++;
                        nep -= nbc;
                        ld -= ldbc;
                    }

                    while(nep >= nbg && ld >= ldbg){
                        bg++;
                        nep -= nbg;
                        ld -= ldbg;
                    }
                }
            }
        }
    }


    else if (strcmp("Fog", w) == 0) {
        if (fibonacci(dc) && fibonacci(dg)) {
            dc /= 2;
            dg /= 2;
        } 
        else {
            dc *= 2;
            dg *= 2;
        }

        nbc = pow(dc, 2) * sqrt(dc);
        nbg = (pow(dg, 2) * PI) / 3;
        ldbc = 1 + (dc >= 8);
        ldbg = 1 + (dg >= 5);
        
        
        while(nep >= nbc && ld >= ldbc){
            bc++;
            nep -= nbc;
            ld -= ldbc;
        }

        while(nep >= nbg && ld >= ldbg){
            bg++;
            nep -= nbg;
            ld -= ldbg;
        }

    }

    
    else if (strcmp("Cloud", w) == 0) {
        if (amicable((int)nep, ld)) {
            fprintf(fout, "0 0 %.3f", nep);
            fclose(fin);
            fclose(fout);
            return 0;
        } 
        
        else {
            
            while(nep >= nbg && ld >= ldbg){
                bg++;
                nep -= nbg;
                ld -= ldbg;
            }
            
            while(nep >= nbc && ld >= ldbc){
                bc++;
                nep -= nbc;
                ld -= ldbc;
            }
            
        }
    }

    nd = nep;

    fprintf(fout, "%d %d %.3f", bc, bg, nd);
    fclose(fin);
    fclose(fout);

    return 0;
}
