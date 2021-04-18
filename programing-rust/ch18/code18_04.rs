use std::fs::OpenOptions;

fn main() {
    let log = OpenOptions::new().append(true).open("server.log")?;

    let file = OpenOptions::new().write(true).create_new(true).open("new_file.txt")?;
}