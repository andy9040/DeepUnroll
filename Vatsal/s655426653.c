m[97][52],C;R(x,y,i,j){if(m[x][y]){m[x][y]=0;for(i=2;~i--;)for(j=2;~j--;)i|j&&R(x+i,y+j);}}main(w,h,x,y){for(;scanf("%d%d",&w,&h)*w;printf("%d\n",C)){for(memset(m,y=0,2e4);y++<h;)for(x=0;x++<w;)scanf("%d",m[x]+y);for(C=y=0;y++<h;)for(x=0;x++<w;)m[x][y]&&R(x,y,C++);}}