#![feature(fn_traits)]
fn main() {
    let mut s = "rush".to_string();

    {
        let mut c = || {
            s += " rust"
        };

        c();
        c();

        c.call_once(());
        // c.call(());

        println!("{:?}", s);
    }

    println!("{:?}", s);
}