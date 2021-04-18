use std::borrow::Cow;
use std::thread;

#[derive(Debug)]
struct Token<'a> {
    raw: Cow<'a, str>,
}

impl<'a> Token<'a> {
    pub fn new<S>(raw: S) -> Token<'a> where S: Into<Cow<'a, str>> {
        Token {
            raw: raw.into()
        }
    }
}

fn main() {
    let _token = Token::new("abc123");
    let token = Token::new("api.example.io".to_string());

    // code5-58
    /*
    let raw = String::from("abc");
    let s = &raw[..];
    let token = Token::new(s);
    */

    thread::spawn(move || {
        println!("token: {:?}", token);
    }).join().unwrap();
}