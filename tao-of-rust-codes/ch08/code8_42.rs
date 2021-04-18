struct Foo;

fn main() {
    let mut vec = Vec::new();
    vec.push(Foo);

    println!("{:?}", vec.capacity());
}