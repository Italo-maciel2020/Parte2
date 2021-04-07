#include "cutsphere.h"

CutSphere::CutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius){
    xcenter=_xcenter; ycenter=_ycenter;
    zcenter=_zcenter; radius=_radius;
}

CutSphere::~CutSphere(){}


void CutSphere::draw(Sculptor &t){
    for(int i= xcenter - radius; i< nx; i++){
      for(int j= ycenter - radius; j< ny; j++){
        for(int k= zcenter - radius; k< nz; k++){
          //equacao da esfera
          if (pow(i-xcenter,2) + pow(j-ycenter,2) + pow(k-zcenter,2) <= pow(radius,2)){
            cutVoxel(i,j,k);
          }
        }
      }
    }
}
