from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.ui import Select
import time
import json


class spanishClass(object):
    state = ""
    school = ""

    # The class "constructor" - It's actually an initializer
    def __init__(self, state, school):
        self.state = state
        self.school = school


def make_spanishClass(state, school):
    result = spanishClass(state, school)
    return result

spanishList = {}
counter = 0
driver = webdriver.Chrome()
driver.get("http://webapps.wichita.edu/TransferEquiv/")
assert "Wichita State University Transfer Equivalency" in driver.title

# elem = driver.find_element_by_name("ctl00$MainContent$Dl_state");
# elem.click();

# for i in range(2,60):

state = Select(driver.find_element_by_name("ctl00$MainContent$Dl_state"));
stateOptions = state.options;

print(len(stateOptions));
for index in range(1, len(stateOptions) - 1):
    state = Select(driver.find_element_by_name("ctl00$MainContent$Dl_state"));
    stateSelected = state.select_by_index(index)
    stateName = driver.find_element_by_xpath('//*[@id="MainContent_Dl_state"]/option[' + str((index + 1)) + ']') \
        .text;
    print(stateName)

    school = Select(driver.find_element_by_name("ctl00$MainContent$Dl_institution"));
    schoolOptions = school.options;
    for index2 in range(1, len(schoolOptions) - 1):
        school = Select(driver.find_element_by_name("ctl00$MainContent$Dl_institution"));
        schoolSelected = school.select_by_index(index2)
        schoolName = driver.find_element_by_xpath(
            '//*[@id="MainContent_Dl_institution"]/option[' + str((index2 + 1)) + ']') \
            .text;
        print(schoolName)

        subject = Select(driver.find_element_by_name("ctl00$MainContent$Dl_subject"));
        subject.select_by_index(1)
        # get starting page after submission

        submitButton = driver.find_element_by_name("ctl00$MainContent$Bt_newresults");
        submitButton.click();
        time.sleep(0.5);
        if driver.find_elements_by_xpath("//*[contains(text(), 'SPAN 300')]"):
            print("Found Span 300");
            spanishList[str(counter)] = {}
            spanishList[str(counter)]['State']= stateName
            spanishList[str(counter)]['School'] = schoolName
            json_data = json.dumps(spanishList)
            print(spanishList)
            print(json_data)
            counter += 1
        else:
            print("NOT found span 300");
        time.sleep(0.5);

        driver.execute_script("window.history.go(-1)");

with open('listOfSchools.txt', 'w') as outfile:
    json.dump(spanishList, outfile)
# elem.click();
# currentState = driver.find_element_by_xpath('//*[@id="MainContent_Dl_state"]/option['+str(i)+']');
# currentState.click();


# elem = driver.find_element_by_name("q")
# elem.clear()
# elem.send_keys("pycon")
# elem.send_keys(Keys.RETURN)
# assert "No results found." not in driver.page_source
#
#
# driver.close()
