#include <iostream>
#include <cstdio>
#include <string>
#include <curl/curl.h>
#include <cstring>
// #include "rapidxml/rapidxml.hpp"
#include <vector>
#include <algorithm>
#include <regex>
#include <fstream>
#include <ctime>
using namespace std;
// using namespace rapidxml;
string data;

size_t writeCallback(char* buf, size_t size, size_t nmemb, void* up)
{
  //callback must have this declaration
  //buf is a pointer to the data that curl has for us
  //size*nmemb is the size of the buffer

  for (int c = 0; c<size*nmemb; c++){
    data.push_back(buf[c]);
  }
  return size*nmemb; //tell curl how many bytes we handled
}

void use_curl(string url){
  CURL *curl;
  CURLcode res;
  curl_global_init(CURL_GLOBAL_ALL); //pretty obvious
  curl = curl_easy_init();

  if (curl){
    curl_easy_setopt(curl, CURLOPT_URL, "https://www.packtpub.com/packt/offers/free-learning");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &writeCallback);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); //tell curl to output its progress
    res = curl_easy_perform(curl);

    // Check for error
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    // always cleanup
    curl_easy_cleanup(curl);
  }
  curl_global_cleanup();
}
string get_book_name(const std::string& input){
  std::smatch matches;
  string s_regex = "(<div class=\"dotd-title\"><h2>)(.*?)(</h2></div>)";
  cout << s_regex << endl;
  regex  txt_regex(s_regex);
  while(regex_search( input, matches, txt_regex)){
    return matches[2];
  }
  return "";

}
string get_current_time(){
  time_t result = time(nullptr);
  string cur_time = asctime(localtime(&result));
  cout << cur_time << endl;
  return cur_time.substr(0,cur_time.size()-1);
  // return "";
}

int main() {
  use_curl("https://www.packtpub.com/packt/offers/free-learning");
  string test =  "<div class=\"dotd-title\"><h2>Spring Data</h2></div>"; 
  data.erase(std::remove(data.begin(), data.end(), '\t'), data.end());
  data.erase(std::remove(data.begin(), data.end(), '\n'), data.end());
  string book_name = get_book_name(data); 
  cout << book_name << endl; 

  ofstream file;
  file.open("data.csv", ios::app);
  file << get_current_time() << " " << book_name << endl; 
  file.close();
  return 0;
}


