library(dplyr)
library(RSQLite)

con <- dbConnect(SQLite(), dbname="soccer.sqlite")
dbListTables(con)
 

player       <- tbl_df(dbGetQuery(con,"SELECT * FROM player"))
player_stats <- tbl_df(dbGetQuery(con,"SELECT * FROM player_attributes"))
match <- tbl_df(dbGetQuery(con, "SELECT * FROM Match"))
team <- tbl_df(dbGetQuery(con, "SELECT * FROM team"))
team_stats <- tbl_df(dbGetQuery(con, "SELECT * FROM team_attributes"))

str(match)

match$bet <- ifelse(
  ((match$B365H < match$B365D) & (match$B365H < match$B365A) & 
    (match$home_team_win == 1)), 1, 0)

colnames(team_stats)[3] <- "home_team_api_id"

m = merge(MyTable, team_stats, by="home_team_api_id")

my_test_set = subset(m, season %in% c("2015/2016", "2014/2015"))

my_test_set_slim[7:9] <- list(NULL) 


my_train_set_slim = subset(my_train_set, (B365H < B365D) & (B365H < B365A) & +(IWH < IWD) & (IWH < IWA))
my_train_set_slim[1:2] <- list(NULL) 
my_train_set_slim[1:8] <- list(NULL) 
my_train_set_slim[7:9] <- list(NULL) 
my_train_set_slim$home_buildUpPlaySpeed <- NULL
my_train_set_slim$bet <- NULL

my_test_set_slim = subset(my_test_set, (B365H < B365D) & (B365H < B365A) & +(IWH < IWD) & (IWH < IWA))
my_test_set_slim[1:2] <- list(NULL) 
my_test_set_slim[1:8] <- list(NULL) 
my_test_set_slim[7:9] <- list(NULL) 
my_test_set_slim$home_buildUpPlaySpeed <- NULL
my_test_set_slim$bet <- NULL

levels(my_train_set_slim$buildUpPlaySpeedClass) <- 1:3
levels(my_train_set_slim$buildUpPlayDribblingClass) <- 1:3
levels(my_train_set_slim$buildUpPlayPositioningClass) <- 1:3
levels(my_train_set_slim$buildUpPlayPassingClass) <- 1:3

my_set_large = subset(m, (B365H < B365D) & (B365H < B365A) & +(IWH < IWD) & (IWH < IWA))
my_set_large[1:2] <- list(NULL) 
my_set_large[1:8] <- list(NULL) 
my_set_large[7:9] <- list(NULL) 
my_set_large$home_buildUpPlaySpeed <- NULL
my_set_large$bet <- NULL

levels(my_set_large$buildUpPlaySpeedClass) <- 1:3
levels(my_set_large$buildUpPlayDribblingClass) <- 1:3
levels(my_set_large$buildUpPlayPositioningClass) <- 1:3
levels(my_set_large$buildUpPlayPassingClass) <- 1:3

my_set_large$buildUpPlaySpeedClass[my_set_large$buildUpPlaySpeedClass == ""] <- 0
my_set_large$buildUpPlayDribblingClass[my_set_large$buildUpPlayDribblingClass == ""] <- 0
my_set_large$buildUpPlayPassingClass[my_set_large$buildUpPlayPassingClass == "Short"] <- 0
my_set_large$buildUpPlayPositioningClass[my_set_large$buildUpPlayPositioningClass == "Form"] <- 0

my_test_set_labels = my_test_set_slim[7]

res_lab$train_set <- as.factor(res_lab$train_set)

spec = c(train_set = .6, test_set = .3, validation_set = .1)
g = sample(cut(seq(nrow(my_set_large)), nrow(my_set_large)*cumsum(c(0,spec)), labels=names(spec)))
res = split(my_set_large, g)
sapply(res, nrow)/nrow(my_set_large)
addmargins(prop.table(table(g)))

scaled_set = scale(my_set_large)
my_large_labels_set = my_set_large[7]
scaled_labels = my_set_large[7]
View(my_large_labels_set)
my_set_large$bet <- NULL

cbind(my_large_labels_set, my_set_large[, 1:10])

