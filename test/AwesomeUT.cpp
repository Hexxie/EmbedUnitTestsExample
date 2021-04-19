#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "awesome_header.h"

#include <memory>

using namespace ::testing;

class AwesomeMock{
public:
    // mock methods
    MOCK_METHOD0(publicFunction,void());
    MOCK_METHOD0(privateFunction,void());
};

class TestFixture: public ::testing::Test{
public:
    TestFixture(){
        _awesomeMock.reset(new ::testing::NiceMock<AwesomeMock>());
    }
    ~TestFixture(){
        _awesomeMock.reset();
    }
    virtual void SetUp(){}
    virtual void TearDown(){}

    // pointer for accessing mocked library
    static std::unique_ptr<AwesomeMock> _awesomeMock;
};

std::unique_ptr<AwesomeMock> TestFixture::_awesomeMock;

void publicFunction(){return TestFixture::_awesomeMock->publicFunction();}
void privateFunction(){return TestFixture::_awesomeMock->privateFunction();}

class B : public TestFixture{
public:
    B(){
        // here you can put some initializations
    }
};

class M {
    public:
    void foo() {};
    int a;
};

TEST(A, openFunction) {
    ASSERT_EQ(openFunction(22), 0);
    M* ptr = nullptr;
    ptr->a = 5;
}


TEST_F(B, closedFunctionWithPublic) {
    EXPECT_CALL(*_awesomeMock,publicFunction()).Times(1);

    closedFunctionWithPublic();
}

TEST_F(B, closedFunction) {
    EXPECT_CALL(*_awesomeMock,privateFunction()).Times(1);

    closedFunction();
}