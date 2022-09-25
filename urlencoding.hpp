#ifndef __URL_ENCODING_HPP__
#define __URL_ENCODING_HPP__

#include <string>

namespace urlencoding {

  extern "C" char* url_encoding_encode(const char* data);

  extern "C" char* url_encoding_encode_binary(const char* data, size_t length);
  
  extern "C" char* url_encoding_decode(const char* data);
  
  extern "C" char* url_encoding_decode_binary(const char* data, size_t length);
  
  extern "C" void url_encoding_free(char* ptr);

  /*
  * Percent-encodes every byte except alphanumerics and -, _, ., ~. Assumes UTF-8 encoding.
  * 
  * Example:
  * * *
  * int main()
  * {
  *     std::string res = urlencoding::encode("This string will be URL encoded.");
  *     std::cout << res <<std::endl;
  *     return 0;
  * }
  * * *
  * 
  * @param data
  * @return encoded string
  */
  std::string encode(const std::string& data)
  {
    auto res = url_encoding_encode(data.c_str());
    if (res == NULL)
    {
      return "";
    }
    std::string str(res);
    url_encoding_free(res);
    return str;
  }

  /*
  * Percent-encodes every byte except alphanumerics and -, _, ., ~.
  * 
  * Example:
  * * *
  * int main()
  * {
  *     std::string res = urlencoding::encodeBinary("This string will be URL encoded.");
  *     std::cout << res <<std::endl;
  *     return 0;
  * }
  * * *
  * 
  * @param data
  * @return encoded string
  */
  std::string encodeBinary(const std::string& data)
  {
    auto res = url_encoding_encode_binary(data.c_str(), data.length());
    if (res == NULL)
    {
      return "";
    }
    std::string str(res);
    url_encoding_free(res);
    return str;
  }

  /*
  * Decode percent-encoded string assuming UTF-8 encoding.
  * 
  * Example:
  * * *
  * int main()
  * {
  *     std::string res = urlencoding::decode("%F0%9F%91%BE%20Exterminate%21");
  *     std::cout << res <<std::endl;
  *     return 0;
  * }
  * * *
  * 
  * @param data
  * @return decoded string
  */
  std::string decode(const std::string& data)
  {
    auto res = url_encoding_decode(data.c_str());
    if (res == NULL)
    {
      return "";
    }
    std::string str(res);
    url_encoding_free(res);
    return str;
  }

  /*
  * Decode percent-encoded string as binary data, in any encoding.
  * 
  * Example:
  * * *
  * int main()
  * {
  *     std::string res = urlencoding::decodeBinary("%F1%F2%F3%C0%C1%C2");
  *     std::cout << res <<std::endl;
  *     return 0;
  * }
  * * *
  * 
  * @param data
  * @return decoded string
  */
  std::string decodeBinary(const std::string& data)
  {
    auto res = url_encoding_decode_binary(data.c_str(), data.length());
    if (res == NULL)
    {
      return "";
    }
    std::string str(res);
    url_encoding_free(res);
    return str;
  }
} // urlencoding

#endif // __URL_ENCODING_HPP__