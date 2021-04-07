#include "putellipsoid.h"

PutEllipsoid::PutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz, float _r, float _g, float _b, float _a){
    xcenter=_xcenter;
    ycenter=_ycenter;
    zcenter=_zcenter;
    rx=_rx; ry=_ry; rz=_rz;
    r=_r; g=_g; b=_b; a=_a;
}

PutEllipsoid::~PutEllipsoid(){}

void PutEllipsoid::draw(Sculptor &t){
    t.setColor(r,g,b,a);
    for(int i=xcenter - rx; i< nx; i++){
      for(int j=ycenter - ry; j< ny; j++){
        for(int k=zcenter - rz; k< nz; k++){
          //equacao da elipsoid
          if ((pow((i-xcenter),2)/pow(rx,2)) + (pow((j-ycenter),2)/pow(ry,2)) + (pow((k-zcenter),2)/pow(rz,2)) <=1.0){
            putVoxel(i,j,k);
          }
        }
      }
    }
}
