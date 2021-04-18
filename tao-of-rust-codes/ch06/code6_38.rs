fn main() {
    let mut s = "rush".to_string();

    {
        let mut c = || {
            s += " rust"
        };

        c();
        c();

        println!("{:?}", s);
    }

    println!("{:?}", s);
}