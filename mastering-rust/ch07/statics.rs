static mut BAZ: u32 = 4;
static FOO: u8 = 9;

fn main() {
    unsafe {
        println!("baz is {}", BAZ);
        BAZ = 42;
        println!("baz now is {}", BAZ);
        println!("foo is {}", FOO);
    }
}