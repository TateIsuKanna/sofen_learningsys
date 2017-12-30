#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	printf("開きたいファイル名を入力してください。\n");
	char fname[20];
        //本当は%msを使って[20]とか決め打ちしないで済むように出来る．getlineを使って手動でパースしてもいい
	scanf("%s",fname);
	FILE* fp = fopen(fname,"r");
	if(fp==NULL){
		printf("ぬるぽ\n");
		return -1;
	}
	
	char c[5000][2][150]={};
        int count=0;
	for(;;){
		if(fscanf(fp,"%s,%s",c[count][0],c[count][1])==EOF){
			break;
		}
                count++;
	}
	
	fclose(fp);
	
	for(int i=0;i<count;i++){		//以下出力
		printf("%s %s\n",c[i][0],c[i][1]);
	}
}
