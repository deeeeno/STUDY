import userService from '../src/users';
import mailService from '../src/mail';

jest.mock("../src/mail");       //jest.fn, jest.spyOn과 다르게 모듈 자체에 걸어버리기

test('jest.mock을 이용한 mocking',()=>{
   
    const user =  {
        email: "test@email.com",
        name:'dino'
    };
    userService.create(user);

    expect(mailService.sendMail).toBeCalledTimes(1);
    expect(mailService.sendMail).toBeCalledWith(user.email,user.name+'님이 가입하였습니다.');
})