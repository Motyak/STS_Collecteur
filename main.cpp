#include <iostream>
#include <vector>    //std::vector
#include "base64/base64.h" //base64_decode()
#include <fstream>

std::vector<unsigned short> convertToByteArray(std::string str);
std::string xorWithKey(std::string data);

//g++ -o main main.cpp base64/base64.cpp -I base64
int main()
{
    const std::string b64="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R29ZS0caHhYNBAgmBgodGEdDSz4kR29ZS0cUDhELAgYmGwQNAzoNCg4cBUdDSz5zS0VZS0c0SUlzS0VZS0dGSW9ZSzhVYUVZSQsYBgBbUUVbJgoNEgQSSUlzS0VbAwQKNBcMCRwmAAAASV9ZDQQVGABVYUVZSQgcHxcQCDoJBwQAHwwUDkdDS1BJR29ZS0cRChYmGAQJGw0QGQAmAAAASV9ZDQQVGABVYUVZSQwKNBELAgQVSV9ZDQQVGABVYUVZSQgcHxcQCDoUCh0mAxUmGwALNAMVBAoLSV9ZMG9ZS0VZXFBzS0UkR29ZS0cKChMcNAEYHwBbUUVIXlBPXlxIXFRMU1BLR29ZS0caChcdGEdDSz5zS0VZSx5zS0VZS0VZSRAJDBcYDwAKSV9ZW0lzS0VZS0VZSQgQGAZbUUVJR29ZS0VZS0VbAgFbUUVbOBELAg4cNCdbYUVZS0UER29ZS0VZEG9ZS0VZS0VbHhUeGQQdDhZbUUVJR29ZS0VZS0VbBgwKCEdDS1VVYUVZS0VZS0cQD0dDS0cqHxcQAAAmKUdzS0VZSxhVYUVZS0UCYUVZS0VZS0cMGwILCgEcGEdDS1VVYUVZS0VZS0cUAhYaSV9ZW0lzS0VZS0VZSQwdSV9ZSTYNGQwSDjo7SW9ZS0VZFklzS0VZSx5zS0VZS0VZSRAJDBcYDwAKSV9ZW0lzS0VZS0VZSQgQGAZbUUVJR29ZS0VZS0VbAgFbUUVbOBELAg4cNCdbYUVZS0UER29ZS0VZEG9ZS0VZS0VbHhUeGQQdDhZbUUVJR29ZS0VZS0VbBgwKCEdDS1VVYUVZS0VZS0cQD0dDS0c9DgMcBQEmKUdzS0VZSxhVYUVZS0UCYUVZS0VZS0cMGwILCgEcGEdDS1VVYUVZS0VZS0cUAhYaSV9ZW0lzS0VZS0VZSQwdSV9ZSSEcDQAXDzo7SW9ZS0VZFklzS0VZSx5zS0VZS0VZSRAJDBcYDwAKSV9ZW0lzS0VZS0VZSQgQGAZbUUVJR29ZS0VZS0VbAgFbUUVbLwAfDgsdNCdbYUVZS0UER29ZS0VZEG9ZS0VZS0VbHhUeGQQdDhZbUUVJR29ZS0VZS0VbBgwKCEdDS1VVYUVZS0VZS0cQD0dDS0c9DgMcBQEmKUdzS0VZSxhVYUVZS0UCYUVZS0VZS0cMGwILCgEcGEdDS1VVYUVZS0VZS0cUAhYaSV9ZW0lzS0VZS0VZSQwdSV9ZST8YG0dzS0VZSxhVYUVZS0UCYUVZS0VZS0cMGwILCgEcGEdDS1VVYUVZS0VZS0cUAhYaSV9ZW0lzS0VZS0VZSQwdSV9ZSSEMCgkaChYNSW9ZS0VZFklzS0VZSx5zS0VZS0VZSRAJDBcYDwAKSV9ZW0lzS0VZS0VZSQgQGAZbUUVJR29ZS0VZS0VbAgFbUUVbOBELDgQUBwwXDkdzS0VZSxhzS0UkR29ZS0ccBQEVDhYKNAwXCBccBgAXHxZbUUUiNklzS0VbBgANGQwaNAwNDggKNBUMGQIcD0dDSz4kR29ZS0cJHhceDiYWGBFbUUVOXklzS0VbGQoWBjoBSV9ZX0lzS0VbCQkQDA0NNAYWHgsNDhcKSV9ZMDhVYUVZSRcWBAgmEkdDS1RVYUVZSQgcHxcQCDoeBAkdNBUcGTofBwoWGUdDSz5zS0VZS1RIX29ZSzhVYUVZSQgcHxcQCDoJBBEQBAsKNAMVBAoLNBAKCgIcSV9ZMDhVYUVZSQcWGBYmBwwKH0dDSz5zS0VZS0cxDh0YDA0WGBFbR29ZS0VZSTERDkU+HgQLDwwYBUdVYUVZS0VbOAkQBgBZKQoKGEdzS0UkR29ZS0cYAjoKDgAdNAYWHgsNSV9ZW0lzS0VbDhMcBREmCA0YBQYcGEdDSz5zS0VZS1VXW0lzS0VZS1VXWklzS0VZS1VXW1ZVYUVZS0VJRVVLYUVZNklzS0VbBgANGQwaNAcWGBYmGQAVAgYKSV9ZMDhVYUVZSRccBwwaNBYcDgEmCAoMBRFbUUVMR29ZS0cYCBEmBRAUSV9ZWklzS0VbBgANGQwaNAEYBgQeDjoNCg4cBUdDSz5zS0VZSx5zS0VZS0VZSQEYBgQeDkdDS1VVYUVZS0VZS0ccBQAUAgAKSV9ZSSYMBxEQGBFbR29ZS0VZS0VbDQkWBBdbUUVIR29ZS0VZS0VbHxALBRZbUUVKYUVZS0UEYUVZNklzS0VbDBccDgtbUUVJR29ZS0cUEhYNDhcANAgYCA0QBQBbUUVIR29ZS0cUDhELAgYmCAQUGwMQGQAmHhUeGQQdDgFbUUVJR29ZS0cJBBEQBAsmGAkWHxZbUUVKR29ZS0caAwoKDjoXDgoONBccHAQLD0dDSwMYBxYcR29ZS0ccHQAXHzoKDgAdNAYWHgsNSV9ZW0lzS0VbBgANGQwaNBccBwwaGDoWCREYAgscD0dDSz4kR29ZS0cdCgwVEjodChEcSV9ZWl1JWlNVYUVZSQobHwQQBQAdNAYYGQEKSV9ZEG9ZS0VZSTYNGQAYBgkQBQBbUUVIYUVZFklzS0VbGwkYEjoNAggcSV9ZXlVVYUVZSQ0YBQEmGAwDDkdDS1BVYUVZSQgYEzoRDgQVHw1bUUVOXklzS0VbBgoXGBEcGToKDgAdNAYWHgsNSV9ZWFZVYUVZSRUWHwwWBRZbUUUiYUVZS0VbOwoNAgoXSzYVBBFbR29ZS0VZSTUWHwwWBUUqBwoNSUlzS0VZS0cpBBEQBAtZOAkWH0dzS0UkYRg=";

    std::string jsonStr=xorWithKey(base64_decode(b64));
    std::ofstream ofs("save.json");
    ofs << jsonStr;
    ofs.close();

    return 0;
}

//convertit en tableau de code ASCII
std::vector<unsigned short> convertToByteArray(std::string str)
{
    std::vector<unsigned short> res;
    for(int i=0;i<str.length();++i)
        res.push_back((unsigned short)str[i]);
    return res;
}

std::string xorWithKey(std::string data)
{
    std::vector<char> v;
    auto vec1=convertToByteArray(data);
    auto vec2=convertToByteArray("key");
    for(int i=0;i<data.length();++i)
        //bitwise XOR '^'
        v.push_back((char)(vec1[i] ^ vec2[i%3]));
   std::string res(v.begin(),v.end());
   return res;
}

