#![feature(unboxed_closures, fn_traits)]
struct Closure {
    env_var: u32,
}

impl FnOnce<()> for Closure {
    type Output = u32;
    extern "rust-call" fn call_once(self, args: ()) -> u32 {
        println!("call it FnOnce()");

        self.env_var + 2
    }
}

impl FnMut<()> for Closure {
    extern "rust-call" fn call_mut(&mut self, args: ()) -> u32 {
        self.env_var + 2
    }
}

impl Fn<()> for Closure {
    extern "rust-call" fn call(&self, args: ()) -> u32 {
        self.env_var + 2
    }
}

fn call_it<F: Fn() -> u32>(f: &F) -> u32 {
    f()
}

fn call_it_mut<F: FnMut() -> u32>(f: &mut F) -> u32 {
    f()
}

fn call_it_once<F: FnOnce() -> u32>(f: F) -> u32 {
    f()
}

fn main() {
    let env_var = 1;
    let mut c = Closure {
        env_var
    };

    c();

    c.call(());
    c.call_mut(());
    c.call_once(());

    let mut c = Closure {
        env_var
    };

    {
        println!("{:?}", &c);
    }

    {
        println!("{:?}", call_it_mut(&mut c));
    }

    {
        println!("{:?}", call_it_once(c));
    }
}