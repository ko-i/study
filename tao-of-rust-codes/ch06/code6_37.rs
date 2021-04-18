fn call<F: FnOnce()>(f: F) {
    f()
}

fn main() {
    // not use move
    let mut x = 0;
    let incr_x = || x += 1;

    call(incr_x);
    // call(incr_x);

    // use move
    let mut x = 0;
    let incr_x = move || x += 1;
    call(incr_x);
    call(incr_x);

    // use move for move
    let mut x = vec![];
    let expend_x = move || x.push(42);
    call(expend_x);
    // call(expend_x);

}