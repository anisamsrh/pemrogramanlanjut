#include <iostream>
using namespace std;

class PersegiPanjang {
    public :
        int xmin, xmax, ymin, ymax;
        
        PersegiPanjang(int x, int y, int width, int height) {
            xmin = x - width/2;
            xmax = x + width/2;
            ymin = y - height/2;
            ymax = y + height/2;
        }
        
        PersegiPanjang operator + (const PersegiPanjang& lain) {
            if (this->xmin >= lain.xmin && this->xmin <= lain.xmax) {
                int width = this->xmax - lain.xmin;
                int x = lain.xmin + width/2;
                if (this->ymin >= lain.ymin && this->ymin <= lain.ymax) {
                    int height = this->ymax - lain.ymin;
                    int y = lain.ymin + height/2;
                    return PersegiPanjang(x, y, width, height);
                } else if (this->ymax >= lain.ymin && this->ymax <= lain.ymax) {
                    int height = lain.ymax - this->ymin;
                    int y = this->ymin + height/2;
                    return PersegiPanjang(x, y, width, height);
                }
            } else if (this->xmax >= lain.xmin && this->xmax <= lain.xmax) {
                int width = lain.xmax - this->xmin;
                int x = this->xmin + width/2;
                if (this->ymin >= lain.ymin && this->ymin <= lain.ymax) {
                    int height = this->ymax - lain.ymin;
                    int y = lain.ymin + height/2;
                    return PersegiPanjang(x, y, width, height);
                } else if (this->ymax >= lain.ymin && this->ymax <= lain.ymax) {
                    int height = lain.ymax - this->ymin;
                    int y = this->ymin + height/2;
                    return PersegiPanjang(x, y, width, height);
                }
            }
        }
        
        PersegiPanjang operator ++ (int u) {
            this->xmax += (this->xmax - this->xmin);
            this->ymax += (this->ymax - this->ymin);
            // return;
        }
        
        PersegiPanjang operator -- (int u) {
            this->xmax -= (this->xmax - this->xmin)/2;
            this->ymax -= (this->ymax - this->ymin)/2;
            // return;
        }
        
        bool operator == (const PersegiPanjang& lain) const {
            if (this->xmin >= lain.xmin && this->xmin <= lain.xmax) {
                if (this->ymin >= lain.ymin && this->ymin <= lain.ymax) {
                    return true;
                } else if (this->ymax >= lain.ymin && this->ymax <= lain.ymax) {
                    return true;
                }
            } else if (this->xmax >= lain.xmin && this->xmax <= lain.xmax) {
                if (this->ymin >= lain.ymin && this->ymin <= lain.ymax) {
                    return true;
                } else if (this->ymax >= lain.ymin && this->ymax <= lain.ymax) {
                    return true;
                }
            } else {
                return false;
            }
        }
        
        const double& operator [] (int index) const {
            switch (index) {
                case 0 :
                    return this->xmin;
                    break;
                case 1 :
                    return this->ymin;
                    break;
                case 2 :
                    return this->xmax;
                    break;
                case 3 :
                    return this->ymax;
                    break;
            }
        }
};

int main()
{
    PersegiPanjang biru(10, 10, 4, 6);
    PersegiPanjang merah(12, 10, 4, 6);
    cout << biru.xmax - biru.xmin << endl;
    biru++;
    cout << biru.xmax - biru.xmin << endl;
    biru--;
    cout << biru.xmax - biru.xmin << endl;
    if (merah == biru) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    cout << biru[0] << endl;

    return 0;
}
