#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *fp;
	char fname[20];
	char save1[2][150]={};
	char save2[2][150]={};
	char c[5000][2][150]={};	//改行文字の関係で配列を3個使って終了判定をしています。
	
	
	printf("開きたいファイル名を入力してください。\n");
	scanf("%s",fname);
	fp = fopen(fname,"r");
	if(fp==NULL){
		printf("ぬるぽ\n");
		return -1;
	}
	
	int i,j,k;
	i=1;
	fscanf(fp,"%[^,],%s",c[0][0],c[0][1]);
	fscanf(fp,"%[^,],%s",save1[0],save1[1]);
	for(;;){
		if(fscanf(fp,"%[^,],%s",save2[0],save2[1])==EOF){
			break;
		}
		for(j=0;j<2;j++){
			for(k=0;k<150;k++){
				c[i][j][k]=save1[j][k];
				save1[j][k]=save2[j][k];
			}
		}
		i++;
	}
	
	fclose(fp);
	
	for(i=0;i<5000;i++){		//以下出力
		if(c[i][0][0]=='\0'){
			break;
		}
		//printf("%s",c[i][5]);
		printf("%s %s",c[i][0],c[i][1]);
	}
	printf("\n");
	return 0;
}
