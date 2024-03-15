#include<iostream>
#include<memory>
class Image{};
class BitmapImage:public Image { public:BitmapImage(){std::cout<<"BitmapImage\n";}    };
class PngImage:public Image{ public:PngImage(){std::cout<<"PngImage\n";}      };
class JpgImage:public Image{ public:JpgImage(){std::cout<<"JpgImage\n";}      };

struct IImageFactory
{
virtual std::unique_ptr<Image>Create(std::string_view type)=0;
};
struct ImageFactory: public IImageFactory/*Factory is fkt or class creating another object*/
{
std::unique_ptr<Image>Create(std::string_view type) /*override*/
{
if(type=="bmp")return std::make_unique<BitmapImage>();
else if(type=="png")return std::make_unique<PngImage>();
else if(type=="jpg")return std::make_unique<JpgImage>();
return nullptr;
}
};
int main(){
auto factory=ImageFactory();
auto image=factory.Create("png");
return 0;
}

