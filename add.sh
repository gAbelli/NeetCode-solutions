#!/bin/bash

find . -type f ! -empty | xargs -I {} git add {}
