# nepotism-queue

Have you ever been hurt by the existence of nepotism? Yes? Have you even been bleeding on a hospital's floor while some deputy's children are getting everything without waiting in lines?
Congratulations! Now you can feel yourself God with our new concept of queue: `nepotism-queue`. Now, only you can decide if an instance is important enough to make everybody wait.

## Key-features

`void push(const T& val)` -- adds an instance to the end of your queue. 


`void push_nep(const T& val)` -- adds an instance after between important instances and non-important instances in your queue.


`pop` / `front` always take instances from the important ones if there are any.
