from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time
import random
from selenium.common.exceptions import NoSuchElementException

# dcap = dict(DesiredCapabilities.PHANTOMJS)

# dcap["phantomjs.page.settings.userAgent"] = (
#     "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_6) AppleWebKit/537.36 (KHTML, like Gecko)"
#     "Chrome/60.0.3112.90 Safari/537.36")

#driver = webdriver.PhantomJS(desired_capabilities=dcap)

def check_exists_by_xpath(xpath):
    try:
        driver.find_element_by_xpath(xpath)
    except NoSuchElementException:
        return False
    return True

def login():

    driver.find_element_by_xpath('//*[@id="react-root"]/section/main/article/div[2]/div[2]/p/a').click() #loginPrompt
    username = driver.find_element_by_xpath('//*[@id="react-root"]/section/main/article/div[2]/div[1]/div/form/div[1]/div/input')
    username.send_keys('thewisdomwhisperer')
    password = driver.find_element_by_xpath('//*[@id="react-root"]/section/main/article/div[2]/div[1]/div/form/div[2]/div/input')
    password.send_keys('PerroPerrone1994')
    password.send_keys(Keys.ENTER)
    print("Logged In")


def home():
    driver.get('https://www.instagram.com/thewisdomwhisperer/')
    time.sleep(5)



def follow_top(acaso):
    counter = 0
    acaso = not(acaso)
    if acaso == True:
        print("Following Chris")
        driver.get('https://www.instagram.com/chrisburkard/')
    else:
        print("Following Morris")
        driver.get('https://www.instagram.com/doyoutravel/')
    time.sleep(3)
    driver.find_element_by_xpath(
        '//*[@id="react-root"]/section/main/article/header/div[2]/ul/li[2]/a').click() #followers
    time.sleep(3)
    scr1 = driver.find_element_by_xpath('/html/body/div[4]/div/div[2]/div/div[2]/div/div[2]')
    for b in range(30):
        if b == 10 or b == 20:
            for i in range(3):
                driver.execute_script("arguments[0].scrollTop = arguments[0].scrollHeight", scr1)
                time.sleep(random.randint(3000, 5000) / 1000)
        if(counter < 8):
            follow = driver.find_element_by_xpath("/html/body/div[4]/div/div[2]/div/div[2]/div/div[2]/ul/li[" + str(b + 1) + "]/div/div[2]/span/button")
            print(follow.text)
            if(follow.text == 'Follow'):
                driver.find_element_by_xpath(
                "/html/body/div[4]/div/div[2]/div/div[2]/div/div[2]/ul/li[" + str(b + 1) + "]/div/div[2]/span/button").click() #follow
                time.sleep(2)
                follow2 = driver.find_element_by_xpath("/html/body/div[4]/div/div[2]/div/div[2]/div/div[2]/ul/li[" + str(
                    b + 1) + "]/div/div[2]/span/button")
                if(follow2.text == 'Requested'):
                    print("NOPE requested...")
                    driver.find_element_by_xpath(
                        "/html/body/div[4]/div/div[2]/div/div[2]/div/div[2]/ul/li[" + str(b + 1) + "]/div/div[2]/span/button").click() #requested! unfollow
                else:
                    counter += 1
                    print("Followed:" + str(counter))
                    time.sleep(random.randint(500, 1000) / 1000)

def likes_only():
    for l in range(10):
        driver.find_element_by_xpath(
            '/html/body/div[3]/div/div[2]/div/div[2]/div/article/div[2]/section[1]/a[1]').click()
        time.sleep(random.randint(500, 1000) / 1000)
        driver.find_element_by_xpath('/html/body/div[3]/div/div[2]/div/div[1]/div/div/a[2]').click()
        time.sleep(2)
        while (check_exists_by_xpath('/html/body/div/div[1]/div/div/h2')):
            driver.get('https://www.instagram.com/explore/tags/travelphotography/')
            time.sleep(3)
            driver.find_element_by_xpath('//*[@id="react-root"]/section/main/article/div[2]/div[1]/div[4]/div[3]/a/div/div[2]').click()
            time.sleep(2)
        print("Liked:" + str(l))
        time.sleep(3)


def hashtag():
    driver.get('https://www.instagram.com/explore/tags/travelphotography/') #hashtagPage
    time.sleep(3)
    driver.find_element_by_xpath('//*[@id="react-root"]/section/main/article/div[2]/div[1]/div[1]/div[1]/a/div'
                                 '/div[2]').click() #hashtagBottomLeftPic
    time.sleep(4)
    while (check_exists_by_xpath("/html/body/div/div[1]/div/div/h2")):
        driver.get('https://www.instagram.com/explore/tags/travelphotography/')  # hashtagPage
        time.sleep(3)
        driver.find_element_by_xpath('//*[@id="react-root"]/section/main/article/div[2]/div[1]/div[1]/div[1]/a/div'
                                     '/div[2]').click()  # hashtagBottomLeftPic
        time.sleep(4)

def like_comment():
    comments = ['Great pic!!', 'Wow! Amazing shot, I love it', 'Good one :)', 'Fantastic :)']
    lc = 0
    while(lc < 2):
        driver.find_element_by_xpath(
            '/html/body/div[3]/div/div[2]/div/div[2]/div/article/div[2]/section[1]/a[1]').click()
        time.sleep(3)
        if(driver.find_element_by_xpath(
            '/html/body/div[3]/div/div[2]/div/div[2]/div/article/div[2]/section[3]/form/textarea')):
            temp = driver.find_element_by_xpath(
                '/html/body/div[3]/div/div[2]/div/div[2]/div/article/div[2]/section[3]/form/textarea')
            temp.send_keys(comments[lc])
            time.sleep(2)
            temp.send_keys(Keys.ENTER)
            time.sleep(4)
            print("Commented:" + str(lc))
            driver.find_element_by_xpath('/html/body/div[3]/div/div[2]/div/div[1]/div/div/a[2]').click()
            time.sleep(3)
            lc +=1


def unfollow():
    counter_unf = 0
    driver.find_element_by_xpath(
        '//*[@id="react-root"]/section/main/article/header/div[2]/ul/li[3]/a').click()  # ourFollowings
    time.sleep(4)
    scr1 = driver.find_element_by_xpath('/html/body/div[4]/div/div[2]/div/div[2]/div/div[2]')
    time.sleep(2)

    for i in range(40):
        driver.execute_script("arguments[0].scrollTop = arguments[0].scrollHeight", scr1)
        time.sleep(random.randint(3000, 5000) / 1000)

    for n in range(50, 58):
        if(driver.find_element_by_xpath("/html/body/div[4]/div/div[2]/div/div[2]/div/div[2]/ul/li[" + str(n) + "]"
                                                                                                                   "/div/div[1]/div/div[1]/a").text not in untouchable_list):
            time.sleep(2)
            driver.find_element_by_xpath(
                "/html/body/div[4]/div/div[2]/div/div[2]/div/div[2]/ul/li[" + str(n) + "]/div/div[2]/span/button").click()
            counter_unf += 1
            print("Unfollowed:" + str(counter_unf))
            time.sleep(random.randint(500, 1000) / 1000)





def my_main():

    print("------- Going to home -------")
    home()
    time.sleep(3)

    print("------- Starting unfollowing -------")
    unfollow()
    time.sleep(2)

    print("------- Strating Chris following -------")
    follow_top(acaso)
    time.sleep(2)

    print("------- Hashtag page -------")
    hashtag()
    time.sleep(3)

    print("------- Liking only -------")
    likes_only()
    time.sleep(3)

    print("------- Like and comment -------")
    like_comment()



untouchable_list = ['maxrivephotography', 'alexstrohl', 'chrisburkard', 'wonderful_places', 'bestvacation', 'nois7',
                    'alexisren', 'jayalvarrez', 'jacob', 'helloemilie', 'samuelelkins', 'dylan furst', 'lifeandmylens',
                    'lastingvisual', 'natgeotravel', 'backpack.vibes', 'campeveryday', 'sefa yamak', 'tomrus', 'theolator',
                    'iamarux', 'bokehm0n', 'muradosmann', 'eljackson', 'gypsea_lust', 'sashajuliard', 'travelandleisure',
                    'iuriebelegurschi', 'coryrichards', 'noriegaphotography', 'wilderness_culture', 'calsnape', 'lebackpacker',
                    'muenchmax', 'hannes_becker', 'tonyrobbins', 'luca_sguazzini', 'l_e_a_w', 'doyoutravel', 'thinkcreateexplore',
                    'earthsroamer']


#
# options = webdriver.ChromeOptions()
# options.binary_location = '/Users/leonardoperrone/Applications (Parallels)/{052be9b7-573a-4ef9-bad1-1a90cc3c1d49} Applications.localized/Google Chrome.app/Contents/MacOS/WinAppHelper'
# options.add_argument('headless')
# options.add_argument('window-size=1200x600')
# driver = webdriver.Chrome(chrome_options=options)
acaso = True
driver = webdriver.Chrome()
driver.get('https://www.instagram.com')


print("------- Logging in -------")
login()
time.sleep(7)

while True:
    start_time = time.time()
    my_main()
    print("--- %s minutes ---" % ((time.time() - start_time)/60))
    print("------- Waiting -------")
    time.sleep(500)

