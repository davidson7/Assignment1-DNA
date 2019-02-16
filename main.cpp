#include <iostream>
#include <fstream> //file read/write
#include <cstdlib> //for exit
#include <string>
#include <cctype> //for upper/lower
#include <cstring> //for string compare
#include <cmath> //for variance and stand dev
//#include <stdlib> //for rand

using namespace std;

int main(int argc, char *argv[]){
  ifstream inStream;
  ofstream outStream;

//user didn't enter file in command line
  if(argc<2){
    cout << "You didn't enter a file name"<< endl;
    exit(0);
  }

//open user's file and check for fail
  inStream.open(argv[1]);
  if(inStream.fail()){
    cout << "Opening input file failed. Make sure file is in the same folder\n";
    exit(1);
  }

//open output file and check for fail
  outStream.open("DanaDavidson.out");
  if(outStream.fail()){
    cout<<"Opening outputfile failed\n";
    exit(1);
  }

//declare count vars and set to 0
  int countA, countT, countG, countC;
  countA =0;
  countT=0;
  countC=0;
  countG=0;
  double nucleotideCount=0;
  int lineCount=0;
  int totalStrLengthSum =0;
  string bigram="";
  int bigramCount=0;
  double stringMean=0;

  double aaCount=0;
  double acCount=0;
  double atCount=0;
  double agCount=0;

  double caCount=0;
  double ccCount=0;
  double ctCount=0;
  double cgCount=0;

  double taCount=0;
  double tcCount=0;
  double ttCount=0;
  double tgCount=0;

  double gaCount=0;
  double gcCount=0;
  double gtCount=0;
  double ggCount=0;

  //read and count each line in txt file
  while(!inStream.eof()){
    lineCount+=1;

  string line1;
  inStream>>line1;


//skip invalid lines
int badLine=0;
for (int i=0; i<line1.length();++i){
  char c = tolower(line1[i]);
  if((c!= 'a')&&(c!='t')&&(c!='c')&&(c!='g')){
    badLine+=1;
  }
}
    //set string to all lower and count nucleotides
    if(badLine==0){
    for (int i=0; i<line1.length();++i){
        char c = tolower(line1[i]);
        //cout << c;
        if(c=='a'){
          countA+=1;
        }if(c=='g'){
          countG+=1;
        }if(c=='c'){
          countC+=1;
        }if(c=='t'){
          countT+=1;
        }

    }

    //count length of string
    totalStrLengthSum+=line1.length();


    //count nucleotide bigrams
    for(int i =0; i<line1.length();i+=2){
      bigramCount +=1;
      bigram += line1[i];
      bigram+=line1[i+1];
      if(!strcmp(bigram.c_str(),"aa")){
        aaCount+=1;
      }if(!strcmp(bigram.c_str(),"ac")){
        acCount+=1;
      }if(!strcmp(bigram.c_str(),"at")){
        atCount+=1;
      }if(!strcmp(bigram.c_str(),"ag")){
        agCount+=1;
      }if(!strcmp(bigram.c_str(),"ca")){
        caCount+=1;
      }if(!strcmp(bigram.c_str(),"cc")){
        ccCount+=1;
      }if(!strcmp(bigram.c_str(),"ct")){
        ctCount+=1;
      }if(!strcmp(bigram.c_str(),"cg")){
        cgCount+=1;
      }if(!strcmp(bigram.c_str(),"ta")){
        taCount+=1;
      }if(!strcmp(bigram.c_str(),"tc")){
        tcCount+=1;
      }if(!strcmp(bigram.c_str(),"tt")){
        ttCount+=1;
      }if(!strcmp(bigram.c_str(),"tg")){
        tgCount+=1;
      }if(!strcmp(bigram.c_str(),"ga")){
        gaCount+=1;
      }if(!strcmp(bigram.c_str(),"gc")){
        gcCount+=1;
      }if(!strcmp(bigram.c_str(),"gt")){
        gtCount+=1;
      }if(!strcmp(bigram.c_str(),"gg")){
        ggCount+=1;
      }
      bigram ="";
    }


}


}
//while loop ends
//print counts for the file

cout<< "Num of A: " << countA << endl;
cout<< "Num of C: " << countC << endl;
cout<< "Num of G: " << countG << endl;
cout<< "Num of T: " << countT << endl;

cout <<"AA: "<< aaCount<<endl;
cout <<"AC: "<< acCount<<endl;
cout <<"AT: "<< atCount<<endl;
cout <<"AG: "<< agCount<<endl;

cout <<"CA: "<< caCount<<endl;
cout <<"CC: "<< ccCount<<endl;
cout <<"CT: "<< ctCount<<endl;
cout <<"CG: "<< cgCount<<endl;

cout <<"TA: "<< taCount<<endl;
cout <<"TC: "<< tcCount<<endl;
cout <<"TT: "<< ttCount<<endl;
cout <<"TG: "<< tgCount<<endl;

cout <<"GA: "<< gaCount<<endl;
cout <<"GC: "<< gcCount<<endl;
cout <<"GT: "<< gtCount<<endl;
cout <<"GG: "<< ggCount<<endl;

//print nucleotide and bigram calculations

nucleotideCount = countA+countC+countT+countG;
cout<<"Probability of A Nucleotide: "<<(countA/nucleotideCount)<<endl;
cout<<"Probability of C Nucleotide: "<<(countC/nucleotideCount)<<endl;
cout<<"Probability of G Nucleotide: "<<(countG/nucleotideCount)<<endl;
cout<<"Probability of T Nucleotide: "<<(countT/nucleotideCount)<<endl;

cout <<"Probability of AA: "<< aaCount/bigramCount<<endl;
cout <<"Probability of AC: "<< acCount/bigramCount<<endl;
cout <<"Probability of AT: "<< atCount/bigramCount<<endl;
cout <<"Probability of AG: "<< agCount/bigramCount<<endl;

cout <<"Probability of CA: "<< caCount/bigramCount<<endl;
cout <<"Probability of CC: "<< ccCount/bigramCount<<endl;
cout <<"Probability of CT: "<< ctCount/bigramCount<<endl;
cout <<"Probability of CG: "<< cgCount/bigramCount<<endl;

cout <<"Probability of TA: "<< taCount/bigramCount<<endl;
cout <<"Probability of TC: "<< tcCount/bigramCount<<endl;
cout <<"Probability of TT: "<< ttCount/bigramCount<<endl;
cout <<"Probability of TG: "<< tgCount/bigramCount<<endl;

cout <<"Probability of GA: "<< gaCount/bigramCount<<endl;
cout <<"Probability of GC: "<< gcCount/bigramCount<<endl;
cout <<"Probability of GT: "<< gtCount/bigramCount<<endl;
cout <<"Probability of GG: "<< ggCount/bigramCount<<endl;




//calulate mean
stringMean = totalStrLengthSum/lineCount;

//read the file again to get strlength for variance
inStream.clear();
inStream.seekg(0, inStream.beg);

string line2;

int tempVariance=0;
int finalVariance=0;
double standDev=0.0;

while(!inStream.eof()){
  inStream>>line2;

    //check for invalid lines again
  int badLine=0;
  for (int i=0; i<line2.length();++i){
    char c = tolower(line2[i]);
    if((c!= 'a')&&(c!='t')&&(c!='c')&&(c!='g')){
      badLine+=1;
    }
  }

      if(badLine==0){
  int lineVariance = pow((line2.length()-stringMean), 2);
  tempVariance+=lineVariance;
}
}
//calculate variance and stand deviation
finalVariance = tempVariance/lineCount;
standDev = sqrt(finalVariance);

//print sum, mean, variance and stand dev for string length
cout<<"Sum of String Lengths: "<< totalStrLengthSum<<endl;
cout<<"Mean String Length: "<< stringMean<<endl;
cout<<"String Length Variance: "<<finalVariance<<endl;
cout<<"String Standard Deviation: "<<standDev<<endl;

//output name, id and all stats to .outfile

outStream<<"Dana Davidson\nID:2299509\nCPSC 350-02\nAssignement1-DNA\n\n";

outStream<<"Sum of String Lengths: "<< totalStrLengthSum<<endl;
outStream<<"Mean String Length: "<< stringMean<<endl;
outStream<<"String Length Variance: "<<finalVariance<<endl;
outStream<<"String Standard Deviation: "<<standDev<<endl;

outStream<<"Probability of A Nucleotide: "<<(countA/nucleotideCount)<<endl;
outStream<<"Probability of C Nucleotide: "<<(countC/nucleotideCount)<<endl;
outStream<<"Probability of G Nucleotide: "<<(countG/nucleotideCount)<<endl;
outStream<<"Probability of T Nucleotide: "<<(countT/nucleotideCount)<<endl;

outStream <<"Probability of AA: "<< aaCount/bigramCount<<endl;
outStream <<"Probability of AC: "<< acCount/bigramCount<<endl;
outStream <<"Probability of AT: "<< atCount/bigramCount<<endl;
outStream <<"Probability of AG: "<< agCount/bigramCount<<endl;

outStream <<"Probability of CA: "<< caCount/bigramCount<<endl;
outStream <<"Probability of CC: "<< ccCount/bigramCount<<endl;
outStream <<"Probability of CT: "<< ctCount/bigramCount<<endl;
outStream <<"Probability of CG: "<< cgCount/bigramCount<<endl;

outStream <<"Probability of TA: "<< taCount/bigramCount<<endl;
outStream <<"Probability of TC: "<< tcCount/bigramCount<<endl;
outStream <<"Probability of TT: "<< ttCount/bigramCount<<endl;
outStream <<"Probability of TG: "<< tgCount/bigramCount<<endl;

outStream <<"Probability of GA: "<< gaCount/bigramCount<<endl;
outStream <<"Probability of GC: "<< gcCount/bigramCount<<endl;
outStream <<"Probability of GT: "<< gtCount/bigramCount<<endl;
outStream <<"Probability of GG: "<< ggCount/bigramCount<<endl;

//generate DNA strings
float a = static_cast <float> (rand())/static_cast<float>(RAND_MAX);
float b = static_cast <float> (rand( ))/static_cast<float>(RAND_MAX);

int D = standDev*(sqrt(-2*log(a)) * acos(2*M_PI*b)) + stringMean;


//close in and out files
inStream.close();
outStream.close();

}
