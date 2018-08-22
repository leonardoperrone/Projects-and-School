import {Component, Input, OnInit} from '@angular/core';
import {GalleryService} from '../../../services/gallery.service';
import {AngularFireDatabase} from 'angularfire2/database';
import {AngularFireStorage} from 'angularfire2/storage';
import {Observable} from 'rxjs/Observable';
import * as _ from 'lodash';

@Component({
  selector: 'app-gallery',
  templateUrl: './gallery.component.html',
  styleUrls: ['./gallery.component.css']
})
export class GalleryComponent implements OnInit {

  // @Input() public country;
  // pictures: Picture[] = [];
  errorMessage: string;
  courseObservable: Observable<any[]>;
  pictures = new Array(10);
  countries = ['belize', 'england', 'france', 'germany', 'guatemala', 'ireland', 'italy', 'portugal', 'studio', 'switzerland'];
  countriesMock = ['belize', 'england', 'france', 'germany', 'guatemala', 'ireland', 'italy', 'portugal', 'studio', 'switzerland'];
  folder = null;
  url = 'https://cdn2-www.dogtime.com/assets/uploads/2011/03/puppy-development-460x306.jpg';
  public picLinkArr = [];
  public loaded = false;

  constructor(private galleryService: GalleryService, private db: AngularFireDatabase, private dbStorage: AngularFireStorage) {

    // const imageStorageRef = dbStorage.storage.ref().child('pictures/' + 1 + '.jpg');
    // imageStorageRef.getDownloadURL().then(url => {
    //   this.url = url;
    //   console.log(url);
    // });
  }

  ngOnInit() {
    // if (this.dbStorage.storage.ref().child(this.folder + '/' + 2 + '.jpg')) {
    //   const imageStorageRef = this.dbStorage.storage.ref().child( + 2 + '.jpg');
    //   imageStorageRef.getDownloadURL().then(url => {
    //     this.url = url;
    //     console.log(url);
    //   });
    // }
    this.countriesMock.map((country) => {
      let url = '/assets/images/banners/' + country + '.jpg';
      console.log(url);
      this.picLinkArr.push(url);
      if (this.picLinkArr.length !== 10) {
        this.loaded = true;
      }
    });

  }

  countrySelected(country: string) {
    this.picLinkArr = [];
    for (let i = 0; i < 10; i++) {
      if (this.dbStorage.storage.ref().child(country + '/' + (i + 1) + '.jpg')) {
        const imageStorageRef = this.dbStorage.storage.ref().child(country + '/' + (i + 1).toString() + '.jpg');
        imageStorageRef.getDownloadURL().then(url => {
          // console.log(url);
          //this.url = url;
          this.picLinkArr.push(url);
          console.log('link arr', this.picLinkArr);

        });
      }
    }
  }

  countrySelectedMock(country: string) {
    for (let i = 1; i <= 10; i++) {
      let url = './images/banners/' + country + '/' + i + '.jpg';
      console.log(url);
      this.picLinkArr.push(url);
    }

  }

  generateUrl(index): any {
    console.log('folder');
    console.log('index', index);

    if (this.dbStorage.storage.ref().child(this.folder + '/' + (index + 1) + '.jpg')) {
      // const imageStorageRef = this.dbStorage.storage.ref().child(this.folder + '/' + (index + 1).toString() + '.jpg');
      // imageStorageRef.getDownloadURL().then(url => {
      //   console.log(this.url);
      //   this.url = url;
      // });
    }
    // return this.url;
  }

}
