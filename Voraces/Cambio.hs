{-# LANGUAGE TypeApplications #-}

import Data.Bifunctor

main = interact 
  ( show 
  . first reverse
  . (\(ls, c) ->
      foldl (\(cs, r) d -> (r `div` d : cs, r `mod` d)) ([], c) ls)
  . read @([Int], Int))