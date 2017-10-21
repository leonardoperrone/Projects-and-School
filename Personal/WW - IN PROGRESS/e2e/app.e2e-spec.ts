import { TheWisdomWhispererPage } from './app.po';

describe('the-wisdom-whisperer App', () => {
  let page: TheWisdomWhispererPage;

  beforeEach(() => {
    page = new TheWisdomWhispererPage();
  });

  it('should display welcome message', () => {
    page.navigateTo();
    expect(page.getParagraphText()).toEqual('Welcome to app!!');
  });
});
