import userService from '../src/users';
import mailService from '../src/mail';

mailService.sendMail = jest.fn();
const sendMail = mailService.sendMail;
beforeEach(()=>{
    sendMail.mockClear();   //모킹된거 지워버리기.
});

test('jest.fn을 이용한 mocking',()=>{
    const user =  {
        email: "test@email.com",
        name:'dino'
    };
    userService.create(user);

    expect(mailService.sendMail).toBeCalledTimes(1);
    expect(mailService.sendMail).toBeCalledWith(user.email,user.name+'님이 가입하였습니다.');
});