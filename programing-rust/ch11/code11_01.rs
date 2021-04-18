use std::io::Write;

fn say_hello(out: &mut dyn Write) -> std::io::Result<()> {
    out.write_all(b"Hello world!\n")?;
    out.flush()
}

fn say_hello_t<W: Write>(out: &mut W) -> std::io::Result<()> {
    out.write_all(b"Hello world!\n")?;
    out.flush()
}

use std::fs::File;

fn main() {
    let mut local_file = File::create("hello").expect("Error");
    say_hello(&mut local_file).expect("Error");

    let mut bytes = vec![];
    say_hello(&mut bytes).expect("Error");
    println!("{:?}", bytes);
}