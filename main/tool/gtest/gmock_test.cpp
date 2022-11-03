#include <gtest/gtest.h>
#include <gmock/gmock.h>

class FooInterface {
public:
    virtual ~FooInterface() { //析构函数必须是virtual
    }

    virtual std::string getArbitraryString() = 0;

    virtual int getPosition(int n) = 0;

    virtual void setValue(std::string& value){};

    virtual void setDoubleValues(int x, int y){};
};


class MockFoo : public FooInterface { // MockFoo类继承 FooInterface
public:
    MOCK_METHOD0(getArbitraryString,std::string());
    MOCK_METHOD1(getPosition,int(int));
    MOCK_METHOD1(setValue, void(std::string& value));
    MOCK_METHOD2(setDoubleValues, void(int x, int y));
};


TEST(TestField, foo) {
    MockFoo mockFoo; //声明一个MockFoo的对象：mockFoo

    //定义一个期望行为，其中Times(1)的意思是运行一次，WillOnce(Return(value))的意思是第一次运行时把value作为getArbitraryString()方法的返回值。
    EXPECT_CALL(mockFoo, getArbitraryString())
        .Times(1)
        .WillOnce(::testing::Return("Hello World!"));

    std::string returnValue = mockFoo.getArbitraryString();
    std::cout << "Returned Value: " << returnValue << std::endl;

    //在这里Times(2)意思是调用两次，但是下边只调用了一次，所以会报出异常
    EXPECT_CALL(mockFoo, getPosition(1))
        .Times(::testing::AtLeast(1))
        .WillOnce(::testing::Return(100))
        .WillRepeatedly(::testing::Return(200));

    int val = mockFoo.getPosition(1); // 100
    std::cout << "Returned Value: " << val << std::endl;
    val = mockFoo.getPosition(1);     // 200
    std::cout << "Returned Value: " << val << std::endl;
    val = mockFoo.getPosition(1);     // 200
    std::cout << "Returned Value: " << val << std::endl;
    val = mockFoo.getPosition(1);     // 200
    std::cout << "Returned Value: " << val << std::endl;
    std::string fiv= mockFoo.getArbitraryString();
    std::cout << "Returned Value: " << returnValue << std::endl;

}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}
