#[derive(Clone, Debug)]
struct Dummy {
    items: u32
}

fn main() {
    let a = Dummy {
        items: 64
    };

    let b = a.clone();
    println!("a: {:?}, b: {:?}", a, b);
}