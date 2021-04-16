#include "interpretador.h"
#include <fstream>
#include <sstream>
#include "putbox.h"
#include "cutbox.h"
#include "putvoxel.h"
#include "cutvoxel.h"
#include <iostream>
#include <vector>

Interpretador::Interpretador(){

}

std::vector<FiguraGeometrica*> Interpretador::parse(std::string filename){
    std::vector<FiguraGeometrica*> figs;
    std::ifstream fin;
    std::stringstream ss;
    std::string s,token;

    fin.open(filename.c_str());
    if(!fin.is_open()){
        std:cout << "nao abriu" << filename << std::endl;
        exit(0);
    }
 while(fin.good()){
     std::getline(fin,s);
     if(fin.good()){
         ss.clear();
         ss.str(s);
         ss >> token;
         if(ss.good()){
             if(token.compare("dim") == 0){
                 ss >> dimx >> dimy >> dimz;
             }
             else if (token.compare("putvoxel") == 0){
                 int x0,y0,z0;
                 ss >> x0 >> y0 >> z0 >> r >> g >> b >> a;
                 figs.push_back(new PutVoxel(x0,y0,z0,r,g,b,a));
             }
             else if(token.compare("putsphere") == 0){
                 int x0,y0,z0,rr;
                 ss >> x0 >> y0 >> z0 >> rr >> r >> g >> b >> a;
                 figs.push_back(new PutSphere(x0,y0,z0,rr,r,g,b,a));
             }
             else if(token.compare("putellipsoid") == 0){
                 int x0,y0,z0,rr;
                 ss >> x0 >> y0 >> z0 >> xcenter >> ycenter >> zcenter >> r >> g >> b >> a;
                 figs.push_back(new PutEllipsoid(x0,y0,z0,xcenter,ycenter,zcenter,r,g,b,a));
             }
         }
     }
 }
return(figs);
}
int Interpretador::getDimx(){
    return dimx;
}

int Interpretador::getDimy(){
    return dimy;
}
int Interpretador::getDimz(){
    return dimz;
}


