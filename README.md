# liburlencoding-cpp

[![](https://img.shields.io/github/v/tag/thechampagne/liburlencoding-cpp?label=version)](https://github.com/thechampagne/liburlencoding-cpp/releases/latest) [![](https://img.shields.io/github/license/thechampagne/liburlencoding-cpp)](https://github.com/thechampagne/liburlencoding-cpp/blob/main/LICENSE)

C++ binding for **liburlencoding**.

### API

```cpp
namespace urlencoding {
  std::string encode(const std::string& data);

  std::string encodeBinary(const std::string& data);

  std::string decode(const std::string& data);

  std::string decodeBinary(const std::string& data);
}
```

### References
 - [liburlencoding](https://github.com/thechampagne/liburlencoding)

### License

This repo is released under the [MIT](https://github.com/thechampagne/liburlencoding-cpp/blob/main/LICENSE).
