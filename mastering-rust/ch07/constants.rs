const HEADER: &'static [u8; 4] = b"Obj\0";

fn main() {
    println!("{:?}", HEADER);
}