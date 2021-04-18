#[macro_use]
extern crate lazy_static;

use regex::Regex;

const TO_SEARCH: &'static str = "On 2020-12-31, happy. On 2021-01-01, New Year.";

lazy_static! {
    static ref RE: Regex = Regex::new(r"(?x)(?P<year>\d{4})-(?P<month>\d{2})-(?P<day>\d{2})").unwrap();
    static ref EMAIL_RE: Regex = Regex::new(r"(?x)^\w+@(?:gmail|163|qq)\.(?:com|cn|com\.cn|net)$").unwrap();
}

fn regex_date(text: &str) -> regex::Captures {
    RE.captures(text).unwrap()
}

fn regex_email(text: &str) -> bool {
    EMAIL_RE.is_match(text)
}

fn main() {
    let re = Regex::new(r"(\d{4})-(\d{2})-(\d{2})").unwrap();

    for caps in re.captures_iter(TO_SEARCH) {
        println!("year: {:?}, month: {:?}, day: {:?}", caps.get(1).unwrap().as_str(), caps.get(2).unwrap().as_str(), caps.get(3).unwrap().as_str());
    }

    let _re = Regex::new(r"(?x)(?P<year>\d{4})-(?P<month>\d{2})-(?P<day>\d{2})").unwrap();

    let caps = regex_date("2020-03-14");
    println!("{:?}", &caps["year"]);
    println!("{:?}", &caps["month"]);
    println!("{:?}", &caps["day"]);

    let after = RE.replace_all("2020-03-14", "$month/$day/$year");
    println!("{:?}", after);

    println!("{:?}", regex_email("akson@gmail.com"));
    println!("{:?}", regex_email("akson@gamil.cn.com"));
}
