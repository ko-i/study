use std::ffi::OsStr;
use std::path::Path;

fn main() {
    let path = Path::new("~/Desktop/favcon.ico");

    for item in path.iter() {
        println!("{:?}", item);
    }
}