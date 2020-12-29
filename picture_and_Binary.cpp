#include <iostream>
using namespace std;
int main()
{
	string sPicPath = CCFileUtils::sharedFileUtils()->getWritablePath() + "test.png";
	string sSavePath=CCFileUtils::sharedFileUtils()->getWritablePath()+ "mysavePic.bat";
	int nRead = 0;
	char chBuf[256] = {0};

	FILE *fin = fopen(sPicPath.c_str(), "rb");
	FILE *fout = fopen(sSavePath.c_str(), "wb");

	if(fin == NULL || fout == NULL)
	{	
	   return false;
	}
	nRead = fread(chBuf,sizeof(char), 256, fin);
	while (true)
	{
		fwrite(chBuf, sizeof(char), 256, fout);
		if(nRead < 256) break;
		nRead = fread(chBuf, sizeof(char), 256, fin);
	}
	fclose(fin);
	fclose(fout);

	string sPicPath = CCFileUtils::sharedFileUtils()->getWritablePath() + "voiceOn.png";
	string sSavePath = CCFileUtils::sharedFileUtils()->getWritablePath()+"mysavePic.bat";
	int nRead = 0;

	unsigned long pSize = 0;
	unsigned char * pBuffer = NULL;
	FILE *fp = fopen(sPicPath.c_str(),"rb");
	if(!fp) return false;

	fseek(fp, 0, SEEK_END);
	pSize = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	pBuffer =  new unsigned char[ pSize];
	if(!pBuffer) return false;
	pSize = fread(pBuffer, sizeof(unsigned char), pSize, fp);
	fclose(fp);

	FILE *fout = fopen(sSavePath.c_str(), "wb");
	if(!fout) return false;
	unsigned long nWSize = 0;
	fseek(fout, 1024, SEEK_SET);
	nWSize = fwrite(pBuffer, sizeof(unsigned char), pSize, fout);
	fclose(fout);

	delete[] pBuffer;
	pBuffer = 0;
}