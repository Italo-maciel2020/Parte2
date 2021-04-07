#include "cutellipsoid.h"

CutEllipsoid::CutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz){
    xcenter=_xcenter;
    ycenter=_ycenter;
    zcenter=_zcenter;
    rx=_rx;
    ry=_ry;
    rz=_rz;
}

CutEllipsoid::~CutEllipsoid(){}


void CutEllipsoid::draw(Sculptor &t){
    for(int i=xcenter - rx; i< nx; i++){
      for(int j=ycenter - ry; j< ny; j++){
        for(int k=zcenter - rz; k< nz; k++){
          //equacao da elipsoide.
           if ((pow((i-xcenter),2)/pow(rx,2)) + (pow((j-ycenter),2)/pow(ry,2)) + (pow((k-zcenter),2)/pow(rz,2)) <=1.0){
            cutVoxel(i,j,k);
          }
        }
      }
   }
}
