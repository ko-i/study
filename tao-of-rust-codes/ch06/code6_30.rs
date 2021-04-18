fn main() {
    let s = "hello";
    let c = ||{
        println!("{:?}", s)
    };

    c();
    c();
    println!("{:?}", s);
}