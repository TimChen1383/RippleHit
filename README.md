# RippleHit
Generate ripple effect on the hit target. Ripple center based on the hit location. Use timeline and dynamic material to update the ripple effect. 

To make it works, you need to :
- Assign M_HitRipple to the actor's ripple material slot
- Assign a mesh to the actor's ripple mesh slot
- Assign a float curve to the actor's ripple curve slot (timeline will read this float curve value)
- In BP_Projectile, call "Ripple Effect" function when the ball get hit. Send the hit location into Ripple Effect function

![RippleHit](https://github.com/TimChen1383/RippleHit/assets/37008451/dc72805d-d3e5-41be-a0fb-75db0605bf83)

