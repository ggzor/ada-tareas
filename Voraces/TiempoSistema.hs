import Data.List

main = interact (show . sum . fmap sum . inits . sort . read)